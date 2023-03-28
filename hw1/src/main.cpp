#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string get_SUB(const std::string& str, int n, char sep)
{
    std::istringstream iss(str);
    std::string field;
    for (int i = 1; i <= n; ++i)
    {
        if (!std::getline(iss, field, sep))
        {
            // Если разделитель не найден, вернуть пустую строку
            return "";
        }
    }
    return field;
}
class line_class
{
public:
    std::vector<std::string> vector;
    std::string next;
    std::ifstream &fname;
    int id;

    // Конструктор класса
    line_class(std::ifstream &file) : fname(file)
    {
        // Инициализация полей класса
        vector.clear();
        getline(fname, next);

        next = "tt0000000";
        id = 0;
        get_next();
    }

    // Деструктор класса
    ~line_class()
    {
        // Очистка вектора
        vector.clear();
    }

    int get_next()
    {
        vector.clear();

        if (fname.is_open())
        {

            vector.push_back(next);
            id = stoi(vector[0].substr(2, 7));
            while (getline(fname, next) && stoi(next.substr(2, 7)) == id)
            {

                vector.push_back(next);
            }

            if (fname.eof())
            {
                return 0;
            }

            return 1;
        }
        return 0;
    }
    std::string find(std::string tcons)
    {
        int id_num = 0;
        try
        {
            id_num = std::stoi(tcons.substr(2, 7));
        }
        catch (std::invalid_argument const &e)
        {
            std::cerr << "Error: argument tcons is not an integer" << std::endl;
            return "FAIL";
        }

        while (tcons.size() >= 7 && id_num >= id)
        {
            if (id_num == id)
            {
                for (int i = 0; i < vector.size(); i++)
                {
                    if (tcons == get_SUB(vector[i], 1, '\t'))
                    {
                        return vector[i];
                    }
                }
                return "FAIL";
            }
            else
            {
                if (!get_next())
                    return "FAIL";
                try
                {
                    id_num = std::stoi(tcons.substr(2, 7));
                }
                catch (std::invalid_argument const &e)
                {
                    std::cerr << "Error: argument tcons is not an integer" << std::endl;
                    return "FAIL";
                }
            }
        }
        return "FAIL";
    }
};

bool isValidArguments(int argc)
{
    if (argc != 6)
    {
        std::cerr << "Usage: ./program_name name.basics.tsv title.akas.tsv title.basics.tsv title.principals.tsv Name" << std::endl;
        return false;
    }

    return true;
}

std::string findNameNumber(std::ifstream &fname, const std::string &name)
{
    std::string name_num;
    if (fname.is_open())
    {
        std::string line;
        while (getline(fname, line))
        {
            if (name == get_SUB(line, 2, '\t'))
            {
                if (get_SUB(line, 5, '\t').substr(0, 3) == "act")
                {
                    name_num = line.substr(0, 9);
                    break;
                }
            }
        }
    }
    return name_num;
}
std::string findAlias(line_class &akas, const std::string &name_num)
{
    std::string buff = akas.find(name_num);
    if (buff != "FAIL")
    {
        for (int i = 0; i < akas.vector.size(); i++)
        {
            std::string akasid(get_SUB(akas.vector[i], 1, '\t'));
            std::string akas_lang(get_SUB(akas.vector[i], 4, '\t'));
            if (akasid == name_num && "RU" == akas_lang)
            {
                return get_SUB(akas.vector[i], 3, '\t');
            }
        }
        return get_SUB(buff, 3, '\t');
    }
    return "FAIL";
}
std::string findBasic(line_class &bas, const std::string &name_num)
{
    std::string buff = bas.find(name_num);
    if (buff != "FAIL" && get_SUB(buff, 5, '\t') == "0")
    {
        return buff;
    }
    return "FAIL";
}
void printActressName(line_class &akas, line_class &bas, line_class &princ, const std::string &name_num)
{
    if (princ.fname.is_open())
    {
        while (princ.get_next())
        {
            for (int i = 0; i < princ.vector.size(); i++)
            {
                std::string prin = princ.vector[i];
                if (prin == "")
                {
                    break;
                }

                std::string prinid ( get_SUB(prin, 1, '\t'));
                std::string prin_numid (get_SUB(prin, 3, '\t'));
                std::string prin_act_atr (get_SUB(prin, 4, '\t').substr(0, 3));
                if (name_num == prin_numid && prin_act_atr == "act")
                {
                    std::string basic = findBasic(bas, prinid);
                    if (basic != "FAIL")
                    {
                        std::string alias = findAlias(akas, prinid);
                        if (alias != "FAIL")
                        {
                            std::cout << alias << std::endl;
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (!isValidArguments(argc))
    {
        return 1;
    }

    std::ifstream fname(argv[1]);
    std::ifstream fakas(argv[2]);
    std::ifstream fbas(argv[3]);
    std::ifstream fprinc(argv[4]);
    line_class akas(fakas), bas(fbas), princ(fprinc);
    std::string name(argv[5]);

    std::string name_num = findNameNumber(fname, name);
    printActressName(akas, bas, princ, name_num);

    return 0;
}