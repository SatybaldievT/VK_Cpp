#include <iostream>
#include <fstream>
#include <string>
#include <vector>
std::string get_SUB(std::string str, int n, char sep) {
    std::string word = "";
    int word_count = 0;
    for (char c : str) {
        if (c == sep) {
            word_count++;
            if (word_count == n) {
                break;
            }
            word = "";
        } else {
            word += c;
        }
    }
    if (word_count < n) {
        // Если не найден символ разделитель, вернуть пустую строку
        return "FAIL";
    }
    return word;
}
class line_class {
public:
    std::vector<std::string> vector;
    std::string next;
    std::ifstream * fname;
    int id;
    
    // Конструктор класса
    line_class(std::string name) {
        // Инициализация полей класса
        fname = new std::ifstream(name);   
        vector.clear();
        getline(*fname,next)   ;
        
        next = "tt0000000";
        id = 0;
        get_next();
    }


    // Деструктор класса
    ~line_class() {
        // Очистка вектора

        delete fname;
        vector.clear();
    }

    int  get_next() {
        vector.clear();

        if (fname->is_open())
        {
            
            vector.push_back(next);
            id = stoi(vector[0].substr(2,7 ));
            while (getline(*fname, next) && stoi(next.substr(2,7 )) == id )
            {
                 
                 vector.push_back(next);
                 
            }
            
            if (fname->eof())  return 0;
            
           
            
            return 1;
        }
        return 0;
    }
    std::string find(std::string tcons){
    while (tcons.size() >= 7 && stoi(tcons.substr(2,7 )) >= id){
        if (stoi(tcons.substr(2,7 )) == id) {
            for (int i = 0 ;i < vector.size();i++){
                if(tcons == get_SUB(vector[i],1,'\t')){
                    return vector[i];
                }
            }
            return "FAIL";
        } else {
            if (!get_next()) return "FAIL";
        }
    }
    return "FAIL";
    }
};



int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cerr << "Usage: ./program_name name.basics.tsv title.akas.tsv title.basics.tsv title.principals.tsv Name" << std::endl;
        return 1;
    }

    std::string name_num;
    std::ifstream fname(argv[1]); // открываем файл для чтения
    line_class akas(argv[2]), bas(argv[3]), princ(argv[4]); // открываем файлы для чтения

    std::string name(argv[5]);

    if (fname.is_open())
    {
        std::string line;
        while (getline(fname, line))
        {

            if (name == get_SUB(line, 2,'\t'))
            {

                if (get_SUB(line, 5,'\t').substr(0, 3) == "act")
                {
                    name_num = line.substr(0, 9);

                    break;
                }
            }
        }
    }
    bool b_bas = true;
 
        if (princ.fname->is_open())
        {
            while (princ.get_next())
            {
                for (int i = 0 ; i < princ.vector.size();i++){
                    std::string prin =princ.vector[i] ;
                    if (prin == "") break;
                    if(name_num == get_SUB(prin, 3,'\t') && (get_SUB(prin, 4,'\t').substr(0, 3) == "act")){
                        std::string buff = "";
                        buff = bas.find(get_SUB(prin,1,'\t'));
                        if (buff!="FAIL" && get_SUB(buff, 5,'\t') == "0" ){ 
                            buff = akas.find(get_SUB(prin,1,'\t'));
                            if (buff != "FAIL"){
                                for (int i = 0 ; i < akas.vector.size();i++){
                                   
                                    if(get_SUB(akas.vector[i], 1,'\t') == get_SUB(prin,1,'\t') && "RU" == get_SUB(akas.vector[i], 4,'\t')) {
                                       std::cout<<get_SUB(akas.vector[i], 3,'\t') <<std::endl;
                                        break;
                                    } 
                                    if (i == akas.vector.size() - 1 ){
                                        std::cout<<get_SUB(buff, 3,'\t') <<std::endl;
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }

        }
    return 0;
}
