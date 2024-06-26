#ifndef PARSING_H
#define PARSING_H

#include "helpers.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class parsing {
private:
  using func = std::function<void(const std::vector<std::string> &)>;

  static void isExit(const std::vector<std::string> &s);
  static void isEcho(const std::vector<std::string> &s);
  static void isType(const std::vector<std::string> &s);
  static void isPwd(const std::vector<std::string> &s);
  static void isCd(const std::vector<std::string> &s);
  static void isExternal(const std::vector<std::string> &s, std::string path);

  static std::string existsInPath(const std::string &s);

  static const std::unordered_map<std::string, func> commandMap;

public:
  static void parseCommand(const std::vector<std::string> &s);
};

#endif // PARSING_H
