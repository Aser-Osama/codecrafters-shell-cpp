#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

namespace helpers {
std::vector<std::string> string_split(const std::string &s, char delim);
std::string string_last_instance(const std::string &s,
                                 char delim); // unused but helpful
std::string string_first_instance(const std::string &s,
                                  char delim); // unused but helpful
} // namespace helpers

#endif // HELPERS_H
