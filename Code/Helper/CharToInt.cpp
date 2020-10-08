#include "CharToInt.h"

unsigned int CharToInt(const char& character)
{
	return static_cast<int>(character) - '0';
}
