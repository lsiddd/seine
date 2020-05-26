#pragma once
#include "template_parser.cc"
#include "tags.cc"

std::string get_file_as_string(std::ifstream *web_file);
std::ifstream get_html_file(std::string filename);