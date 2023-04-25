#if !defined(FJHOME_HPP)
#define FJHOME_HPP

#include <algorithm>
#include <cstdlib>
#include <direct.h>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace FJ {
class FolderJunker {
private:
  /* data */
protected:
  std::vector<std::string> random_words_generator(std::string word,
                                                  int numbers);

public:
  FolderJunker(/* args */);
  ~FolderJunker();
  void initializeTitle(bool isSilent);
  void createFolders(const char *folderName, int numbers, bool isDestructive);
  void createFolders(int numbers);
};

} // namespace FJ

#endif // FJHOME_HPP
