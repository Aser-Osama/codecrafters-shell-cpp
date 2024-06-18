#include "parsing.hpp"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>
void parsing::isExit(const std::vector<std::string> &s) {
  if (s.size() == 1)
    exit(-1);

  std::string end = s[1];
  if (!end.empty() && std::all_of(end.begin(), end.end(), isdigit))
    exit(std::stoi(s[1]));
  else
    exit(-1);
}

void parsing::isEcho(const std::vector<std::string> &s) {
  for (size_t i = 1; i < s.size(); i++) {
    std::cout << s[i];
    if (i != s.size() - 1)
      std::cout << ' ';
  }
  std::cout << '\n';
}

void parsing::isType(const std::vector<std::string> &s) {
  if (s.size() == 1 || s[1].empty()) {
    return;
  } else if (commandMap.contains(s[1])) {
    std::cout << s[1] << " is a shell builtin" << std::endl;
  } else {
    std::string path = existsInPath(s[1]);
    if (!path.empty())
      std::cout << s[1] << " is " << path << std::endl;
    else
      std::cout << s[1] << ": not found" << std::endl;
  }
}

std::string parsing::existsInPath(const std::string &s) {
  const char *pathEnv = std::getenv("PATH");
  if (pathEnv) {
    std::string paths_string = pathEnv;
    std::vector<std::string> paths = helpers::string_split(paths_string, ':');
    for (const auto &path : paths) {
      for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string name = entry.path().filename().string();
        if (name == s) {
          return entry.path().string();
        }
      }
    }
  }
  return "";
}

void parsing::execExternal(const std::vector<std::string> &s,
                           std::string path) {
  std::string cmd = path + " ";
  for (size_t i = 1; i < s.size(); i++) {
    cmd += s[i] + " ";
  }
  // std::cout << cmd;
  system(cmd.c_str());
}

const std::unordered_map<std::string, parsing::func> parsing::commandMap = {
    {"exit", parsing::isExit},
    {"echo", parsing::isEcho},
    {"type", parsing::isType}};

void parsing::parseCommand(const std::vector<std::string> &s) {
  if (s.empty() || s[0].empty())
    return;

  auto it = commandMap.find(s[0]);
  if (it != commandMap.end()) {
    it->second(s);
  } else {
    std::string path = existsInPath(s[0]);
    if (path.empty()) {
      std::cout << s[0] << ": command not found" << std::endl;
    } else {
      execExternal(s, path);
    }
  }
}
