#include "fjhome.hpp"

using namespace FJ;

FolderJunker::FolderJunker(/* args */) {}

FolderJunker::~FolderJunker() {}

void FolderJunker::initializeTitle() {
  std::cout << "Folder Junker" << std::endl;
}

// The main createFolders function that creates folders with custom names |
// Overloaded function
void FolderJunker::createFolders(const char *folderName, int numbers,
                                 bool isDestructive) {
  std::cout << "Creating " << numbers << " folders named " << folderName
            << " in this current directory..." << std::endl;

  //     Use the random words generator function to generate random words and
  //     use them as the folder names
  std::vector<std::string> random_words =
      random_words_generator(folderName, numbers);
  if (isDestructive) {
    // CHeck if the folder name already exists or not and if it exists, then
    // delete it and then create a new folder with the same name
    try {
      for (int i = 0; i < numbers; i++) {
        if (_mkdir((random_words[i]).c_str()) == 0)
          std::cout << "Folder " << random_words[i] << " created successfully"
                    << std::endl;
        else {
          std::cout << "Folder " << random_words[i] << " already exists"
                    << std::endl;
          std::cout << "Deleting folder " << random_words[i] << "..."
                    << std::endl;
          std::filesystem::remove_all(random_words[i]);
          std::cout << "Folder " << random_words[i] << " deleted successfully"
                    << std::endl;
          std::cout << "Creating folder " << random_words[i] << "..."
                    << std::endl;
          _mkdir((random_words[i]).c_str());
          std::cout << "Folder " << random_words[i] << " created successfully"
                    << std::endl;
        }
      }
    } catch (...) {
      std::cout << "Errors occured while creating folders." << std::endl;
    }

  } else {
    // check if the generated folder name already exists or not
    // if it exists, then skip that folder name and move to the next name and
    // create that folder if it doesn't exist, then create that folder
    try {
      for (int i = 0; i < numbers; i++) {
        if (_mkdir((random_words[i]).c_str()) == 0)
          std::cout << "Folder " << random_words[i] << " created successfully"
                    << std::endl;
        else
          std::cout << "Folder " << random_words[i] << " already exists"
                    << std::endl;
      }
    } catch (...) {
      std::cout << "Errors occured while creating folders." << std::endl;
    }
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

// This function generates random words using the letters of the given word.
// Takes a word and the number of words to be generated as arguments.
std::vector<std::string> FolderJunker::random_words_generator(std::string word,
                                                              int numbers) {
  // Convert the word to lowercase
  std::transform(word.begin(), word.end(), word.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  // Convert the word to a vector of characters
  std::vector<char> letters(word.begin(), word.end());
  // Shuffle the vector of letters
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(letters.begin(), letters.end(), g);
  // Join the shuffled vector of letters back into a string
  std::string shuffled_word(letters.begin(), letters.end());
  // Create an empty vector to hold the random words
  std::vector<std::string> random_words;
  // Generate numbers random words using the shuffled letters
  for (int i = 0; i <= numbers; i++) {
    std::shuffle(letters.begin(), letters.end(), g);
    std::string random_word(letters.begin(), letters.end());
    random_words.push_back(random_word);
  }
  // Return the vector of random words
  return random_words;
}
