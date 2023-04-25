/*
A pet project of Mushfiqur Rahman Abir under GPL 3.0 License. The intention of
this tool will be to create many dummy/junk folders in just one click. The usage
of this tool will be of course for test purposes. Developed By: Mushfiqur Rahman
Abir Year: 2021 Build System: CMake
*/

// TODO: if 1 is passed then show folder instead of folders

// Includes
#include <cstring>
#include <iostream>

// Personal includes
#include "fjhome.hpp"
#include "help.hpp"
#include "version.hpp"

// Personal Defines
#define COMP !std::strcmp
// Error Codes
#define NEGATIVE_NUMBER 101
#define INVALID_ARG 102
#define UNKNOWN_ERR 103

// Driver Function
int main(int argc, char const *argv[]) {

  if (argc <= 1) /* If no args passed */
    std::cout
        << "No arguments passed. Specify the numbers of folder you want to "
           "create & try again. Example usage: folderJunker 100\n\nSee "
           "folderJunker --help for more info.";
  else /* If args are passed */
  {
    bool hasW = false;
    bool hasN = false;

    std::string word;
    int number;
    FJ::FolderJunker *fj = new FJ::FolderJunker();
    fj->initializeTitle();

    // Check for the version and help commands first and then check for the
    // other. If help or version is passed, then show the help or version and
    // exit the program.
    if (COMP(argv[1], "-v") || COMP(argv[1], "--version")) {
      std::cout << "Current App version: " << FJ::currentVersion << std::endl;
      std::cout << "Developed by: Mushfiqur Rahman Abir\n"
                << "Year: 2021\n";

      exit(0);
    }

    if (COMP(argv[1], "-h") || COMP(argv[1], "--help")) {
      FJ::Help help;
      help.listAvailableCommands();
      exit(0);
    }

    // Check if the user has passed any other arguments or not
    for (int i = 0; i < argc; i++) {
      if (COMP(argv[i], "-w") || COMP(argv[i], "--word")) {
        hasW = true;
        argv[i + 1] == NULL ? word = "folder_Junker" : word = argv[i + 1];
      } else if (COMP(argv[i], "-n") || COMP(argv[i], "--number")) {
        hasN = true;
        number = std::stoi(argv[i + 1]);
        number < 1 ? number = 1 : number = std::stoi(argv[i + 1]);
      }
    }

    // If --number is passed then only check for the --word/other arguments
    // which depends on the --number argument
    if (hasN) {
      if (hasW)
        fj->createFolders(word.c_str(), number);
      else
        fj->createFolders(number);
    } else {
      try {
        int val = std::stoi(argv[1]); // Convert the char* to int

        bool num_accepted = false;
        try {
          if (val < 1)
            throw NEGATIVE_NUMBER;
          else
            num_accepted = true;
        } catch (int errorno) {
          std::cout << "Negative numbers are not accepted. Error no: "
                    << errorno;
          std::cout << std::endl;
        }

        int &number = val; // Reference to the val variable
        if (num_accepted)
          fj->createFolders(number);
      } catch (std::invalid_argument) {
        std::cerr << "Invalid argument passed. Please provide positive numbers "
                     "as arguments. "
                     "Error no "
                  << INVALID_ARG << std::endl;
      } catch (...) {
        std::cerr << "Errors occured ! Please try again. Error no "
                  << UNKNOWN_ERR << std::endl;
      }
    }

    // Delete the fj object
    delete fj;
  }

  return 0;
}
