#include "../head/base.h"
#include <iostream>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    decltype(start) stop = str.find_first_of(d); // здесь decltype
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print(const std::vector<std::vector<int>>& vec){
    for (std::vector<std::vector<int>>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter){
        for (std::vector<int>::const_iterator ite = iter->cbegin(); ite != iter->cend(); ++ite){
            if (ite != iter->begin()){
                std::cout << ".";
            }
            std::cout << *ite;
        }
        std::cout << std::endl;
    }
}