# Fish 
A Shell Client built in C++

[![progress-banner](https://backend.codecrafters.io/progress/shell/d2c1f252-4929-4703-a65a-863874d64979)](https://app.codecrafters.io/users/codecrafters-bot?r=2qF)

This repository contains **Fish**, a POSIX-compliant shell client built in C++ as part of the [Codecrafters "Build Your Own Shell" Challenge](https://app.codecrafters.io/courses/shell/overview). The shell is capable of interpreting shell commands, running external programs, and handling built-in commands like `cd`, `pwd`, `echo`, and more.

<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<!-- ABOUT THE PROJECT -->
## About The Project

Fish is designed to be a lightweight and simple shell client built in C++ that complies with POSIX standards. It is capable of interpreting a variety of shell commands and managing both external programs and built-in shell functionalities.

Key features include:
* Running external programs.
* Built-in commands like `cd`, `pwd`, `echo`, and more.
* Learning about shell command parsing and REPL loops.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

The project uses the following tools and libraries:
* C++
* POSIX standard for shell compliance

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

To get started with Fish locally, follow the steps below.

### Prerequisites

Ensure you have the following installed on your system:
* GCC (or any C++ compiler)
* Make (optional, for easier build management)

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/Ashfinn/fish.git
   ```
2. Navigate to the project directory:
   ```sh
   cd fish
   ```
3. Compile the source code:
   ```sh
   g++ -o fish_shell main.cpp
   ```
4. Run the shell:
   ```sh
   ./fish
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

Once the shell is running, you can execute common shell commands such as:
* `pwd` - Print the current directory.
* `cd` - Change directory.
* `echo` - Output text to the terminal.
* Run external programs like `ls`, `cat`, etc.

You can type commands directly into the Fish shell, just as you would in a standard Unix shell.

_For more usage examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] Add basic command parsing and execution
- [x] Add built-in commands (`cd`, `pwd`, `echo`)
- [ ] Improve error handling and edge case support
- [ ] Support piping and redirection
- [ ] Add support for multi-command execution (using `&&`, `||`)
- [ ] Add additional features like scripting support

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions are welcome! If you have ideas to improve Fish, feel free to fork the repo and create a pull request. Here’s how:
1. Fork the repository
2. Create a new feature branch (`git checkout -b feature/newFeature`)
3. Commit your changes (`git commit -m 'Add some newFeature'`)
4. Push to the branch (`git push origin feature/newFeature`)
5. Open a pull request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Codecrafters](https://app.codecrafters.io/)
* [POSIX Standard](https://pubs.opengroup.org/onlinepubs/9699919799/)
* [GitHub README Template](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/Ashfinn/fish.svg?style=for-the-badge
[contributors-url]: https://github.com/Ashfinn/fish/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Ashfinn/fish.svg?style=for-the-badge
[forks-url]: https://github.com/Ashfinn/fish/network/members
[stars-shield]: https://img.shields.io/github/stars/Ashfinn/fish.svg?style=for-the-badge
[stars-url]: https://github.com/Ashfinn/fish/stargazers
[issues-shield]: https://img.shields.io/github/issues/Ashfinn/fish.svg?style=for-the-badge
[issues-url]: https://github.com/Ashfinn/fish/issues
[license-shield]: https://img.shields.io/github/license/Ashfinn/fish.svg?style=for-the-badge
[license-url]: https://github.com/Ashfinn/fish/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/Ashfinn
