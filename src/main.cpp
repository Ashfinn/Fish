#include <iostream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string input;
  
  while (true) {
    // Read
    std::getline(std::cin, input);
  
    // Evaluate
    if(input == "exit") {
      break;
    }

    // Print input
    std::cout << input << std::endl;
    
    // Loop 

    return 0; 
  }

}
 