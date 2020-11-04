#include <Data/Time/Date/Months.h>
#include <Error/Error.h>
eMonth& operator++(eMonth& orig)
{
	if (orig == eMonth::December)
	{
		Assert("Can't increment month");
	}
	orig = static_cast<eMonth>(static_cast<unsigned int>(orig) + 1);
	return orig;
}

eMonth operator++(eMonth& orig, int)
{
	eMonth rVal = orig;
	++orig;
	return rVal;
}

eMonth& operator--(eMonth& orig)
{
	if (orig == eMonth::January)
	{
		Assert("Can't decrement month");
	}
	orig = static_cast<eMonth>(static_cast<unsigned int>(orig) - 1);
	return orig;
}

eMonth operator--(eMonth& orig, int)
{
	eMonth rVal = orig;
	--orig;
	return rVal;
}

eMonth operator-(const eMonth lhv, const unsigned int rhv)
{
	const unsigned int month = static_cast<unsigned int>(lhv) - rhv;
	if (month < 0)
		Assert("Can't create an enum of negative value");

	return static_cast<eMonth>(month);
}
