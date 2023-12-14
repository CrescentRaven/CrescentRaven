#ifndef CRESCENTRAVEN_H
#define CRESCENTRAVEN_H

#include <string>

// *** Defines

// *** Macros

// Returns the macro-expanded string name of a given value such as a type or variable.
#define NAMEOF(a) __NAMEOF__(a)

// Returns the string name of a given value such as a type or variable.
#define __NAMEOF__(a) #a

namespace CrescentRaven
{
	// *** Type Definitions

	class String
	{
	private:
	protected:
	public:
		static void Replace(std::string &inputString, const std::string &findString, const std::string &replaceString);
		static std::string *Replace(const std::string &inputString, const std::string &findString, const std::string &replaceString);
	};

	// *** Forward Declarations

	// *** Exports

}

#endif
