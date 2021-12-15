#if !defined(FJHOME_HPP)
#define FJHOME_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <direct.h>
#include <string>
namespace FJ
{
	class FolderJunker
	{
	private:
		/* data */
	public:
		FolderJunker(/* args */);
		~FolderJunker();
		void initializeTitle();
		void createFolders(const char *folderName, int numbers);
		void createFolders(int numbers);
	};

} // namespace FJ

#endif // FJHOME_HPP
