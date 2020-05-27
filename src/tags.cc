// #include <iostream>
#include <regex>
#include <include/nlohmann/json.hpp>

#define LOG(x) std::cout << x << std::endl

using json = nlohmann::json;

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
    sort(matches.begin(), matches.end());
    matches.erase(unique(matches.begin(), matches.end()), matches.end());

    return matches;
}

std::vector<std::string> clean_tags(std::vector<std::string> matches)
{
    std::vector<std::string> tags;
    std::regex p1("\\{seine.");
    std::regex p2("\\}");
    for (auto i : matches)
    {
        i = std::regex_replace(i, p1, "");
        i = std::regex_replace(i, p2, "");
        tags.push_back(i);
    }
    return tags;
}

json compare_tags(std::vector<std::string> tags, std::string contents, std::string json_filename)
{
    // read a JSON file
    std::ifstream i(json_filename);
    json j;
    i >> j;

    for (auto i : tags)
    {
        if (!j.contains(i))
        {
            // throw error if template has key that is not present in the jason file
            LOG("Key " << i << " not found in json.");
            throw;
        }
    }

    // return the object
    return j;
}