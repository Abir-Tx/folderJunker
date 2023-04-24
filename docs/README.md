# folderJunker

[![CMake](https://github.com/Abir-Tx/folderJunker/actions/workflows/cmake.yml/badge.svg)](https://github.com/Abir-Tx/folderJunker/actions/workflows/cmake.yml) [![CodeFactor](https://www.codefactor.io/repository/github/abir-tx/folderjunker/badge)](https://www.codefactor.io/repository/github/abir-tx/folderjunker) ![GH Release](https://img.shields.io/github/v/release/Abir-Tx/folderJunker?label=Release)

Create thousands of junk folders in one click

## Usage

- Download the latest release from releases page
- Extract the zip file
- Open command prompt in the extracted folder and run `folderJunker.exe` with the number of folders you want to create as an argument. For example, to create 1000 folders, run `folderJunker.exe 1000`
- You can also add the `folderJunker.exe` to your PATH variable to run it from anywhere

## Building from source

- Clone the repository
- `cd` into the cloned repository & run `mkdir build && cd build`
- Run `cmake -G "Unix Makefiles" ..` or `cmake -G "MinGW Makefiles" ..` depending on your OS and what generator you want to use
- Run `make` or `mingw32-make` depending on your OS
- Run `./folderJunker` to run the program
