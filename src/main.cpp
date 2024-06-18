#include "helpers.hpp"
#include <iostream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (1) {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> input_vector = helpers::split(input, ' ');

    helpers::isExit(input_vector);

    std::cout << input_vector[0] << ": command not found" << std::endl;
  }
}
