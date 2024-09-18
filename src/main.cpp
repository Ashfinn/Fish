#include <iostream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string input;
  
  while (true) {
    std::getline(std::cin, input);
  
    // Evaluate input
    std::cout << input << std::endl;
    return 0; 
  }

}
 