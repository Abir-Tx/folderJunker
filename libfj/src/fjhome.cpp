#include "fjhome.hpp"

using namespace FJ;

FolderJunker::FolderJunker(/* args */) {}

FolderJunker::~FolderJunker() {}

void FolderJunker::initializeTitle() {
  std::cout << "Folder Junker" << std::endl;
}

// The main createFolders function that creates folders with custom names |
// Overloaded function
// TODO: Add a feature to create folders with custom names. This function is
// currently not working.
void FolderJunker::createFolders(const char *folderName, int numbers) {
  std::cout << "Creating " << numbers << " folders named " << folderName
            << " in this current directory..." << std::endl;

  srand(time(0));
  int num = rand() % 100;
  try {
    for (int i = 0; i < numbers; i++)
      _mkdir((std::to_string(num++)).c_str());
    std::cout << "Folder creation successfull" << std::endl;
  } catch (...) {
    std::cout << "Errors occured while creating folders." << std::endl;
  }
}

// The main createFolders function that creates folders with random names
void FolderJunker::createFolders(int numbers) {
  std::cout << "Creating " << numbers << " folders"
            << " in this current directory..." << std::endl;

  srand(time(0));
  int num = rand() % 100;
  try {
    for (int i = 0; i < numbers; i++)
      _mkdir((std::to_string(num++)).c_str());
    std::cout << "Folder creation successfull" << std::endl;
  } catch (...) {
    std::cout << "Errors occured while creating folders." << std::endl;
  }
}