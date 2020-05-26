// #include <iostream>
#include <regex>
using namespace std;

std::vector<std::string> find_tags(std::string contents)
{
    std::string pattern("\\{.*\\}"); // Regex expression
    std::regex rx(pattern);          // Getting the regex object
    std::vector<std::string> matches;

    std::sregex_iterator iter = std::sregex_iterator(contents.begin(), contents.end(), rx);

    auto words_begin =
        std::sregex_iterator(contents.begin(), contents.end(), rx);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        matches.push_back(match_str);
        // std::cout << match_str << '\n';
    }
    sort( matches.begin(), matches.end() );
    matches.erase( unique( matches.begin(), matches.end() ), matches.end() );

    return matches;
}