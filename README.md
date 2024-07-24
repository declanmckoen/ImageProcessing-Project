# TGA Image Editor

The TGA Image Editor is a command-line tool designed to perform a series of operations on TGA image files, modifying their appearance. Functioning as a primitive version of Photoshop, this project allows users to apply various image editing techniques through a command-line interface.

## Features

- **TGA File Support**: Load and manipulate TGA image files.
- **Image Editing Operations**: Perform a series of operations to modify image appearance.
- **Command-Line Interface**: Interact with the program through a command-line interface.
- **Makefile**: Use the provided Makefile to compile and run the executable files easily.

## Project Structure

The project files are organized as follows:
- The C++ code is on the main page of the repository
- The input TGA files are located in the `input` folder
- The program outputs the modified images in the `output` folder

## Getting Started

### Prerequisites

To compile and run this project, you will need:
- A C++ compiler that supports C++11 or later.
- Make utility (commonly available on Unix-based systems).

### Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/declanmckoen/ImageProcessing-Project.git
   cd ImageProcessing-Project
   ```
2. Use the MakeFile to compile the cpp files:
   ```sh
   make
   ```
3. Use the MakeFile to run the executables:
   ```sh
   make run
   ```

**Please note that the makefile is configured for MacOS. If on any other operating system, please modify the MakeFile accordingly.**

## Contributions
Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.
