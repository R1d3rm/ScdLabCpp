#include"base.h"
#include<vector>
#include<string>
#include<iostream>
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
void print(const std::vector<std::vector<int>> &vector)
{
    for (std::vector<std::vector<int>>::const_iterator iter = vector.cbegin(); iter != vector.cend(); ++iter)
    {
        for (std::vector<int>::const_iterator iterate = iter->cbegin(); iterate != iter->cend(); ++iterate)
        {
            if (iterate != iter->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *iterate;
        }
        std::cout << std::endl;
    }
}