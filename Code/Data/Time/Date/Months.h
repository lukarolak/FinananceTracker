#pragma once
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

// prefix (++my_month)
eMonth& operator++(eMonth& orig);

// postfix (my_month++)
eMonth operator++(eMonth& orig, int);

eMonth operator-(const eMonth lhv, const unsigned int rhv);