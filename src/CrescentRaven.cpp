#include "CrescentRaven.h"
using namespace CrescentRaven;

int main()
{
	std::string input = "Hi\nthere.\nSilly\ngoose.\n";
	std::string *replaced = String::Replace((const std::string)input, "\n", "\r\n");
	String::Replace(input, "\n", "\r\n");
}

void String::Replace(std::string &inputString, const std::string &findString, const std::string &replaceString)
{
	std::string *buffer = String::Replace((const std::string)inputString, findString, replaceString);
	inputString.swap(*buffer);
	delete buffer;
}

std::string *String::Replace(const std::string &inputString, const std::string &findString, const std::string &replaceString)
{
	std::string::size_type currPos = 0;
	std::string::size_type prevPos = 0;
	std::string *buffer = new std::string();
	buffer->reserve(inputString.size()); // Reserve at least as much as the current string.

	while ((currPos = inputString.find(findString, currPos)) != std::string::npos)
	{
		buffer->append(inputString, prevPos, currPos - prevPos);
		*buffer += replaceString;
		prevPos = currPos += findString.size();
	}
	buffer->append(inputString, prevPos, inputString.size() - prevPos);
	return buffer;
}
