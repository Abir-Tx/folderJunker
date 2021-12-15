#if !defined(HELP_HPP)
#define HELP_HPP

#include <iostream>
#include "availableCommands.hpp"
namespace FJ
{
	class Help
	{
	private:
	public:
		Help();
		~Help();
		void initHelpMenu();
		void listAvailableCommands();
	};
} // namespace FJ

#endif // HELP_HPP
