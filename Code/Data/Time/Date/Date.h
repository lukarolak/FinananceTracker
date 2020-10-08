#pragma once
#include <Data/Time/Date/Months.h>
class Date
{
public:
	void SetDate(const Date& DateIn);
	bool SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	auto GetYear() const;
	auto GetMonth() const;
	auto GetDay() const;
private:
	bool ValidateDateCorrectness(const unsigned int Year, const unsigned int Month,const unsigned int Day) const;
	bool IsLeapYear(const unsigned int Year) const;
	unsigned int m_year = 0;
	eMonth m_month = eMonth::January;
	unsigned int m_day = 0;
};