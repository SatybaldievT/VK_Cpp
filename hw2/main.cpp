#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Интерфейс операции
class IOperation
{
public:
    virtual void ProcessLine(const std::string &str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation *nextOperation) = 0;
};

class CatOperation : public IOperation
{
private:
    IOperation *nextOperation_;
    std::string filename_;

public:
    CatOperation(const std::string& filename) : filename_(filename), nextOperation_(nullptr) {}

    void ProcessLine(const std::string &str) override
    {
        // Просто передаем строку следующей операции
        if (nextOperation_)
        {
            nextOperation_->ProcessLine(str);
        }else {
            std::cout << str << std::endl;
        }
    }

    void HandleEndOfInput() override
    {
        
        std::ifstream file(filename_);
        
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                

                
                if (nextOperation_) {
                    nextOperation_->ProcessLine(line);
                }else {
                    std::cout << line << std::endl;
                }
            }
            file.close();
        } else {
            std::cerr << "Ошибка открытия файла: " << filename_ << std::endl;
        }
        if (nextOperation_) {
        nextOperation_->HandleEndOfInput();}
    }

    void SetNextOperation(IOperation *nextOperation) override
    {
        nextOperation_ = nextOperation;
    }
};
// Операция "echo"
class EchoOperation : public IOperation
{
private:
    std::string echoString_;
    IOperation *nextOperation_;

public:
    EchoOperation(const std::string &echoString) : echoString_(echoString), nextOperation_(nullptr) {}

    void ProcessLine(const std::string &str) override
    {
        // Игнорируем входную строку, передаем echoString следующей операции
    }

    void HandleEndOfInput() override
    {
        // Вызываем HandleEndOfInput у следующей операции
        if (nextOperation_)
        {
            nextOperation_->ProcessLine(echoString_);
            nextOperation_->HandleEndOfInput();
        }
        else
        {
            std::cout << echoString_ << std::endl;
        }
    }

    void SetNextOperation(IOperation *nextOperation) override
    {
        nextOperation_ = nextOperation;
    }
};

// Операция "nl"
class NLOperation : public IOperation
{
private:
    int lineNumber_;
    IOperation *nextOperation_;

public:
    NLOperation() : lineNumber_(1), nextOperation_(nullptr) {}

    void ProcessLine(const std::string &str) override
    {
        // Добавляем номер строки перед строкой и передаем ее следующей операции
        std::string result = std::to_string(lineNumber_) + ": " + str;
        if (nextOperation_)
        {
            nextOperation_->ProcessLine(result);
        }else {
            std::cout << result << std::endl;
        }
        lineNumber_++;
    }

    void HandleEndOfInput() override
    {
        // Вызываем HandleEndOfInput у следующей операции
        if (nextOperation_)
        {
            nextOperation_->HandleEndOfInput();
        }
    }

    void SetNextOperation(IOperation *nextOperation) override
    {
        nextOperation_ = nextOperation;
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./text_processor '<expression>'" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    // Разбиваем выражение на операции, разделенные символом '|'
    std::stringstream ss(expression);
    std::stringstream tokenStream(expression);
    std::string token;
    std::vector<IOperation *> operations;

    // Создаем объекты операций на основе переданных в выражении аргументов
    while (std::getline(tokenStream, token, '|'))
    {
        if (token.find("cat") == 0)
        {
            std::string catString = token.substr(4);
            operations.push_back(new CatOperation(catString));
        }
        else if (token.find("echo") == 0)
        {
            std::string echoString = token.substr(4); // Получаем строку после "echo" команды
            operations.push_back(new EchoOperation(echoString));
        }
        else if (token.find("nl") == 0)
        {
            operations.push_back(new NLOperation());
        }
        else
        {
            std::cout << "Unknown operation: " << token << std::endl;
            return 1;
        }
    }

    // Связываем операции в цепочку
    for (size_t i = 0; i < operations.size() - 1; i++)
    {
        operations[i]->SetNextOperation(operations[i + 1]);
    }
    
    // Обработка окончания ввода
    operations[0]->HandleEndOfInput();

    // Освобождение памяти, занятой объектами операций
    for (IOperation *operation : operations)
    {
        delete operation;
    }

    return 0;
}