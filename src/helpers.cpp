#include "helpers.hpp"
#include <algorithm>
#include <sstream>
#include <vector>

namespace helpers {
std::vector<std::string> string_split(const std::string &s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  if (result.size() == 0)
    return {""};

  return result;
}

std::string string_last_instance(const std::string &s, char delim) {
  size_t pos = s.rfind(delim);
  if (pos == std::string::npos) {
    return "";
  } else {
    return s.substr(pos + 1);
  }
}

std::string string_first_instance(const std::string &s, char delim) {
  size_t pos = s.find(delim);
  if (pos == std::string::npos) {
    return "";
  } else {
    return s.substr(0, pos);
  }
}

} // namespace helpers