#include "helpers.hpp"
#include <sstream>
#include <vector>

namespace helpers {
std::vector<std::string> split(const std::string &s, char delim) {
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

void isExit(std::vector<std::string> s) {
  if (s[0] == "exit") {
    if (s.size() == 1)
      exit(-1);

    std::string end = s[1];
    if (!(!end.empty() && std::all_of(end.begin(), end.end(), isdigit)))
      exit(-1);
    else
      exit(std::stoi(s[1]));
  } else
    return;
}

}