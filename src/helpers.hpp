#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

namespace helpers {
std::vector<std::string> string_split(const std::string &s, char delim);
void isExit(std::vector<std::string> s);
} // namespace helpers

#endif // HELPERS_H
