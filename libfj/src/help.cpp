#include "help.hpp"

FJ::Help::Help() { initHelpMenu(); };
FJ::Help::~Help() {
  std::cout << "\n________________\n" << std::endl;
  std::cout << "End of Help Menu" << std::endl;
  std::cout << "________________" << std::endl;
}
void FJ::Help::listAvailableCommands() {
  std::cout
      << "\nCurrently available command line arguments in FolderJunker are: "
      << std::endl;
  for (int i = 0; i < (sizeof(availCmd) / sizeof(availCmd[0])); i++) {
    std::cout << availCmd[i] << " " << std::endl;
  }
}

void FJ::Help::initHelpMenu() {
  std::cout << "\n________________\n" << std::endl;
  std::cout << "Help menu for FolderJunker" << std::endl;
  std::cout << "________________\n" << std::endl;

  std::cout
      << "FolderJunker is a simple command line tool that creates folders "
         "with random names. Example usage for creating 100 folders: "
         "folderJunker 100"
      << std::endl;
}