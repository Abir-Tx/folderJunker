#include "fjhome.hpp"

using namespace FJ;

FolderJunker::FolderJunker(/* args */)
{
}

FolderJunker::~FolderJunker()
{
}

void FolderJunker::initializeTitle()
{
	std::cout << "Folder Junker" << std::endl;
}

void FolderJunker::createFolders(const char *folderName, int numbers)
{
	std::cout << "Creating " << numbers << " folders named " << folderName << " in this current directory..." << std::endl;

	srand(time(0));
	int num = rand() % 100;
	try
	{
		for (int i = 0; i < numbers; i++)
			_mkdir(folderName++);
		std::cout << "Folder creation successfull" << std::endl;
	}
	catch (...)
	{
		std::cout << "Errors occured while creating folders." << std::endl;
	}
}