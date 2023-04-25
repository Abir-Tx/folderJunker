/*
A pet project of Mushfiqur Rahman Abir under GPL 3.0 License. The intention of
this tool will be to create many dummy/junk folders in just one click. The usage
of this tool will be of course for test purposes. Developed By: Mushfiqur Rahman
Abir Year: 2021 Build System: CMake
*/

// TODO: if 1 is passed then show folder instead of folders
// TODO: Increase the version number to 2.0.0 when merged
// TODO: Add a new command to delete the folders created by this tool
// TODO: Add a disclaimer or warning when numbers are passed to the -w arg as
// when numbers are passed, the random words generator will not be able to
// create enough random words
// NOTE: the --destructive arg will only work when the -w arg is passed.
// Currently it does not work with the basic createFolders function

// Includes
#include <cstring>
#include <fstream>
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
    // Variables to check CLA
    bool hasW = false;
    bool hasN = false;
    bool isDestructive = false;
    bool isSilent = false;

    // Variables to store the CLA or other values
    std::string word;
    int number;

    // Check if the user has passed the silent arg or not at the very beginning
    // so that any kind of output can be suppressed from the beginning
    for (int i = 0; i < argc; i++) {
      if (COMP(argv[i], "-s") || COMP(argv[i], "--silent")) {
        isSilent = true;
      }
    }

    // Create an object of the FolderJunker class
    FJ::FolderJunker *fj = new FJ::FolderJunker();
    fj->initializeTitle(isSilent);

    // If the user has passed the silent arg then suppress all the output from
    // the std::cout
    std::ofstream devnull("nul");
    // TODO: For working on Linux, change the above line to: std::ofstream
    // devnull("/dev/null");
    std::streambuf *oldCoutStreamBuf;
    if (isSilent) {
      oldCoutStreamBuf = std::cout.rdbuf(devnull.rdbuf());
    }

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
        try {
          number = std::stoi(argv[i + 1]);
        } catch (std::invalid_argument) {
          std::cerr
              << "Invalid argument passed. Please provide positive numbers "
                 "as arguments. "
                 "Error no "
              << INVALID_ARG << std::endl;
        }
        number < 1 ? number = 1 : number = std::stoi(argv[i + 1]);
      } else if (COMP(argv[i], "--destructive")) {
        isDestructive = true;
      }
    }

    // If --number is passed then only check for the --word/other arguments
    // which depends on the --number argument
    if (hasN) {
      hasW ? fj->createFolders(word.c_str(), number, isDestructive)
           : fj->createFolders(number);
    } else { /* Keeping this code for backward version compatibility */
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

    /* CLEANUP */
    // Delete the fj object
    delete fj;
    // Restore the cout buffer
    if (isSilent) {
      std::cout.rdbuf(oldCoutStreamBuf); // restore old cout buffer
      devnull.close();                   // close the null stream
    }

    return 0;
  }
