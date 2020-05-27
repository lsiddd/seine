#include <iostream>
#include <fstream> // std::ifstream
#include <string>
#include <regex>

#include "include/nlohmann/json.hpp"

#include "seine.h"

#define LOG(x) std::cout << x << std::endl
#define wait std::cin.get()

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        LOG("Pass html file.");
        return -1;
    }

    std::ifstream file = get_html_file(argv[1]);
    std::string contents = get_file_as_string(file);

    auto matches = find_tags(contents);
    auto tags = clean_tags(matches);

    json json_obj = compare_tags(tags, contents, "example.json");

    int counter = 0;
    for (auto match : matches)
    {
        std::string value = json_obj[tags[counter]].get<std::string>();
        match.replace(match.find("{"), 1, "\\{");
        match.replace(match.find("}"), 1, "\\}");
        contents = std::regex_replace(contents, std::regex(match), value);
        counter++;
    }

    std::ofstream outfile("out.html");
    outfile << contents;

    return 0;
}