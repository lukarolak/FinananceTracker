#pragma once
#include <string>
enum class eMonth
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

namespace std
{
	inline std::string to_string(const eMonth Month)
	{
		std::string monthInString;
		if (Month >= eMonth::January && Month<= eMonth::October)
		{
			monthInString.append("0");
		}
		monthInString.append(std::to_string(static_cast<const unsigned int>(Month)));
		return monthInString;
	}
}

// prefix (++my_month)
eMonth& operator++(eMonth& orig);
// postfix (my_month++)
eMonth operator++(eMonth& orig, int);
// prefix (++my_month)
eMonth& operator--(eMonth& orig);
// postfix (my_month++)
eMonth operator--(eMonth& orig, int);

eMonth operator-(const eMonth lhv, const unsigned int rhv);