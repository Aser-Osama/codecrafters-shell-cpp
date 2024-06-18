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
} // namespace helpers