#ifndef PARSING_H
#define PARSING_H

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class parsing {
private:
  static void isExit(const std::vector<std::string> &s);
  static void isEcho(const std::vector<std::string> &s);
  static void isType(const std::vector<std::string> &s);
  using func = std::function<void(const std::vector<std::string> &)>;
  static const std::unordered_map<std::string, func> commandMap;

public:
  static void parseCommand(const std::vector<std::string> &s);
};

#endif // PARSING_H
