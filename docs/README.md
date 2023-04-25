# folderJunker

[![CMake](https://github.com/Abir-Tx/folderJunker/actions/workflows/cmake.yml/badge.svg)](https://github.com/Abir-Tx/folderJunker/actions/workflows/cmake.yml) [![CodeFactor](https://www.codefactor.io/repository/github/abir-tx/folderjunker/badge)](https://www.codefactor.io/repository/github/abir-tx/folderjunker) ![GH Release](https://img.shields.io/github/v/release/Abir-Tx/folderJunker?label=Release) ![Downloads Count](https://img.shields.io/github/downloads/Abir-Tx/folderJunker/total?label=Downloads) ![GitHub repo size](https://img.shields.io/github/repo-size/Abir-Tx/folderJunker?label=Repo%20Size) ![License](https://img.shields.io/github/license/Abir-Tx/folderJunker?label=License)

Create thousands of junk folders in just using one command

> Created for educational or testing purposes only. I am not responsible for any damage caused by this program. The program might be
> detected as a virus by your antivirus. This is a false positive. You can check the source code for yourself. So it is recommended to
> disable your antivirus before running this program.

## Usage

- Download the latest release from releases page
- Extract the zip file
- Open command prompt in the extracted folder and run `folderJunker.exe` with the number of folders you want to create as an argument. For example, to create 1000 folders, run `folderJunker.exe 1000`
- You can also add the `folderJunker.exe` to your PATH variable to run it from anywhere

## Available options

```bash
Usage: folderJunker.exe [OPTIONS] NUMBER_OF_FOLDERS

-h, --help                Print this help message and exit
-v, --version             Print version information and exit
-s, --silent              Run silently without printing anything to the console
-w, --word                Create folders with random words generated from the given string
-n, --number              Specify the number of folders to be created
--destructive             Delete all the content of existing folders before creating new ones.

```

## Building from source

- Clone the repository
- `cd` into the cloned repository & run `mkdir build && cd build`
- Run `cmake -G "Unix Makefiles" ..` or `cmake -G "MinGW Makefiles" ..` depending on your OS and what generator you want to use
- Run `make` or `mingw32-make` depending on your OS
- Run `./folderJunker` to run the program

## Contributors

- [Abir-Tx](https://github.com/abir-tx)
