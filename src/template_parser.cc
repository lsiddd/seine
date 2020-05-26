#include <iostream>
#include <fstream> // std::ifstream

#include <string>
#include <fstream>
#include <streambuf>

#define LOG(x) std::cout << x << std::endl

std::string get_file_as_string(std::ifstream &web_file)
{
    std::string str((std::istreambuf_iterator<char>(web_file)),
                    std::istreambuf_iterator<char>());
    return str;
}

std::ifstream get_html_file(std::string filename)
{
    std::ifstream web_template(filename);
    if (web_template)
    {
        return web_template;
    }
    else
    {
        LOG("File not found.");
        throw - 1;
    }
}