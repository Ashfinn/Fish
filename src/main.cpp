

/**
 * @file main.cpp
 * @brief A simple shell implementation in C++ with basic built-in commands.
 *
 * This file contains the implementation of a simple shell that supports
 * basic built-in commands such as 'exit', 'type', and 'echo'. The shell
 * reads user input, parses the command, and executes the corresponding
 * function. The shell also handles errors and provides appropriate
 * messages for unknown commands.
 *
 * Improvements and Fixes:
 * 1. Incorrect use of the 'substr()' method: The current implementation uses
 *    `input.substr(5)` to extract the command from the user input, but it should
 *    start at the position right after the command prefix (e.g., "type" or "echo").
 *    To fix this, change all instances of `input.substr(5)` to `input.substr(command.length())`.
 * 2. The current implementation does not handle multiple arguments for built-in commands
 *    like 'echo'. If a user enters an 'echo' command with multiple arguments, the output
 *    will only include the last argument. To fix this, modify the 'handle_echo()' function
 *    to accept and print all arguments following the command.
 * 3. The current implementation does not handle errors when there is no space between the
 *    command and its arguments. This could lead to unexpected results or errors. To fix this,
 *    modify the extraction of the command from the user input to ensure that it only includes
 *    characters up until the first space character. You can do this by changing `input.find(' ')`
 *    to `input.find(" ")`.
 * 4. Improper handling of built-in commands with a single argument: The current implementation
 *    does not allow for passing arguments to built-in commands like 'type'. To handle this,
 *    modify the 'handle_type()' function to accept and process arguments if present. For example,
 *    implement a version of 'handle_type()' that checks for a second argument and returns the
 *    corresponding message or indicates an error when no such message exists.
 * 5. Lack of proper error handling: In case the command is not found, the current implementation
 *    only prints "<command>: command not found". It would be more user-friendly to provide a
 *    descriptive error message that guides users on how to correctly enter commands. Modify the
 *    main loop to handle different types of errors and print appropriate messages.
 * 6. Add more built-in commands: While this code includes 'exit', 'type', and 'echo' commands,
 *    there are many other useful built-ins you could add, such as 'ls', 'cd', 'pwd', 'mkdir', and 'rm'.
 *    This would help make the shell more functional and user-friendly.
 * 7. Implementing history functionality: It would be a nice addition to implement command history
 *    functionality, allowing users to recall previous commands using up and down arrow keys or some
 *    other input mechanism. You can use libraries like Readline or Ncurses for this purpose.
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to handle the 'type' command
// This function checks if the input command is a known shell builtin
// and prints the corresponding message. If the command is not found,
// it prints "<command>: not found".
void handle_type(const string &input)
{
  map<string, string> type_choice = {
      {"exit", "exit is a shell builtin"},
      {"type", "type is a shell builtin"},
      {"echo", "echo is a shell builtin"}};

  auto it = type_choice.find(input.substr(5));

  // need to fix the segmentation fault
  cout << (it != type_choice.end()) ? it->second : input.substr(5) + ": not found";
}

// Function to handle the 'exit' command
// This function prints a goodbye message and exits the program.
void handle_exit(const string &input)
{
  cout << "Goodbye!" << endl;
  exit(0);
}

// Function to handle the 'echo' command
// This function prints the text following the 'echo' command.
void handle_echo(const string &input)
{
  cout << input.substr(5) << endl;
}

int main()
{
  // Flush after every cout / cerr
  cout << unitbuf;
  cerr << unitbuf;

  // Map of commands to their corresponding handler functions
  map<string, void (*)(const string &)> command_map = {
      {"exit", &handle_exit},
      {"type", &handle_type},
      {"echo", &handle_echo}};

  string input;

  while (true)
  {
    cout << "$ ";
    getline(cin, input);

    // Extract the command from the input
    string command = input.substr(0, input.find(' '));
    auto it = command_map.find(command);

    // If the command is found in the map, call the corresponding function
    if (it != command_map.end())
    {
      it->second(input);
    }
    else
    {
      // If the command is not found, print an error message
      cout << input + ": command not found" << endl;
    }
  }
  return 0;
}