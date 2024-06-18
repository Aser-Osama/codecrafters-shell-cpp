#include "helpers.hpp"
#include "parsing.hpp"
#include <iostream>

int main() {

  while (1) {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> input_vector = helpers::string_split(input, ' ');
    parsing::parseCommand(input_vector);
  }
}
