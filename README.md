
# Custom Shell Implementation

This repository contains a custom shell implementation written in C++. The shell is designed to interpret and execute commands, including built-in commands like `cd`, `pwd`, and `echo` as well as any external programs present in the user's `$PATH`.

## Project Setup

### Prerequisites

Ensure you have [cmake](https://cmake.org/getting-started/) and [vcpkg](https://github.com/microsoft/vcpkg?tab=readme-ov-file#getting-started) installed on your system to build the project. \
Make sure `$VCPKG_ROOT` is set to be the root directory of your vcpkg install.

### Building the Project

Clone the repository and build the project:

```sh
git clone https://github.com/Aser-Osama/codecrafters-shell-cpp.git
cd codecrafters-shell-cpp
```

### Running the Shell

Build and execute the shell using:

```sh
./your_shell
```

This command starts the shell in interactive mode, allowing you to input and execute commands.

