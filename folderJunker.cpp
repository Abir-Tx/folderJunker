/* 
A pet project of Mushfiqur Rahman Abir under GPL 3.0 License. The intention of this tool
will be to create many dummy/junk folders in just one click. The usage of this tool will be of course for test purposes.
Developed By: Mushfiqur Rahman Abir
Year: 2021
Build System: CMake
*/

// Includes
#include <iostream>
#include <cstring>

// Personal includes
#include "fjhome.hpp"

// Personal Defines
#define COMP !std::strcmp
// Error Codes
#define NEGATIVE_NUMBER 101

// Driver Function
int main(int argc, char const *argv[])
{
	if (argc <= 1) /* If no args passed */
		std::cout << "No args passed";
	else /* If args are passed */
	{
		FJ::FolderJunker *fj = new FJ::FolderJunker();
		fj->initializeTitle();

		if (COMP(argv[1], "-v") || COMP(argv[1], "--version"))
			std::cout << "Current App version: v1.0.0";
		else
		{
			int val = std::stoi(argv[1]);
			bool num_accepted = false;
			try
			{
				if (val < 1)
					throw NEGATIVE_NUMBER;
				else
					num_accepted = true;
			}
			catch (int errorno)
			{
				std::cout << "Negative numbers are not accepted. Error no: " << errorno;
				std::cout << std::endl;
			}

			int &number = val;
			if (num_accepted)
				fj->createFolders("makeMe", number);
		}
	}

	return 0;
}
