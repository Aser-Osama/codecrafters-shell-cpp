#include "parsing.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
namespace parsing {

namespace {

void isExit(const std::vector<std::string> &s);
void isEcho(const std::vector<std::string> &s);
void isType(const std::vector<std::string> &s);
using func = std::function<void(const std::vector<std::string> &)>;
static const std::unordered_map<std::string, func> commandMap = {
    {"exit", isExit}, {"echo", isEcho}, {"type", isType}};

void isExit(const std::vector<std::string> &s) {
  if (s.size() == 1)
    exit(-1);

  std::string end = s[1];
  if (!(!end.empty() && std::all_of(end.begin(), end.end(), isdigit)))
    exit(-1);
  else
    exit(std::stoi(s[1]));
}

void isEcho(const std::vector<std::string> &s) {
  for (size_t i = 1; i < s.size(); i++) {
    std::cout << s[i];
    if (i != s.size() - 1)
      std::cout << ' ';
  }
  std::cout << '\n';
}

void isType(const std::vector<std::string> &s) {
  if (s.size() == 1 || s[1].empty()) {
    return;
  } else if (commandMap.contains(s[1])) {
    std::cout << s[1] << " is a shell builtin" << std::endl;
  } else {
    std::cout << s[1] << ": not found" << std::endl;
  }
}

} // namespace

void parseCommand(const std::vector<std::string> &s) {
  if (s.empty() || s[0].empty())
    return;

  auto it = commandMap.find(s[0]);
  if (it != commandMap.end()) {
    it->second(s);
  } else {
    std::cout << s[0] << ": command not found" << std::endl;
  }
}

}; // namespace parsing