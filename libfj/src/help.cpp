#include "help.hpp"

FJ::Help::Help()
{
	initHelpMenu();
};
FJ::Help::~Help()
{
	std::cout << "End of Help Menu" << std::endl;
}
void FJ::Help::listAvailableCommands()
{
	std::cout << "Currently available command line arguments in FolderJunker are: " << std::endl;
	for (int i = 0; i < (sizeof(availCmd) / sizeof(availCmd[0])); i++)
	{
		std::cout << availCmd[i] << " " << std::endl;
	}
}

void FJ::Help::initHelpMenu()
{
	std::cout << "\nHelp menu for FolderJunker\n " << std::endl;
}