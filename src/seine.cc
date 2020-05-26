#include <iostream>
#include <fstream> // std::ifstream

#include "seine.h"

#define LOG(x) std::cout << x << std::endl

int main(int argc, char *argv[])
{
    if (argc < 2){
        LOG("Pass html file.");
        return -1;
    }

    std::ifstream file = get_html_file(argv[1]);
    std::string contents = get_file_as_string(file);

    auto tags = find_tags(contents);

    for (auto i: tags)
        LOG(i);

    return 0;
}