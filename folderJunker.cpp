/*
A pet project of Mushfiqur Rahman Abir under GPL 3.0 License. The intention of
this tool will be to create many dummy/junk folders in just one click. The usage
of this tool will be of course for test purposes. Developed By: Mushfiqur Rahman
Abir Year: 2021 Build System: CMake
*/

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
    FJ::FolderJunker *fj = new FJ::FolderJunker();
    fj->initializeTitle();

    if (COMP(argv[1], "-v") || COMP(argv[1], "--version")) {
      std::cout << "Current App version: " << FJ::currentVersion << std::endl;
      std::cout << "Developed by: Mushfiqur Rahman Abir\n"
                << "Year: 2021\n";
    }

    else if (COMP(argv[1], "-h") || COMP(argv[1], "--help")) {
      FJ::Help help;
      help.listAvailableCommands();
    } else /* For handling  positive int args */
    {
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
