#include "parsing.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

namespace parsing {

namespace {
void isExit(std::vector<std::string> s) {
  if (s.size() == 1)
    exit(-1);

  std::string end = s[1];
  if (!(!end.empty() && std::all_of(end.begin(), end.end(), isdigit)))
    exit(-1);
  else
    exit(std::stoi(s[1]));
}
void isEcho(std::vector<std::string> s) {
  for (size_t i = 1; i < s.size(); i++) {
    std::cout << s[i];
    if (i != s.size() - 1)
      std::cout << ' ';
  }
  std::cout << '\n';
}

} // namespace

void parseCommand(std::vector<std::string> s) {
  if (s.empty() || s[0].empty()) {
    return;
  } else if (s[0] == "exit") {
    isExit(s);
    return;
  } else if (s[0] == "echo") {
    isEcho(s);
    return;
  } else {
    std::cout << s[0] << ": command not found" << std::endl;
  }
}

}; // namespace parsing