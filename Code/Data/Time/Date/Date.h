#pragma once
#include <Data/Time/Date/Months.h>
#include <string>

using dateYear = unsigned int;
using dateDay = unsigned int;

class Date
{
public:
	Date() = default;
	Date(const dateYear m_year, const eMonth m_month, const dateDay m_day);
	bool operator< (const Date& rhv) const;
	bool operator> (const Date& rhv) const;
	Date& operator=(const Date& rhv);

	void SetDate(const Date& DateIn);
	bool SetDate(const dateYear Year, const unsigned int Month, const dateDay Day);
	bool SetDate(const dateYear Year, const eMonth Month, const dateDay Day);
	void SetDateInDays(dateDay Days);
	void AddDateInDays(const dateDay Days);
	unsigned int GetYear() const;
	eMonth GetMonth() const;
	dateDay GetDay() const;
	dateDay GetDateInDays() const;
	unsigned long long GetDateInSeconds() const;
	std::string GetTimeStamp() const;
private:
	static constexpr dateDay GetAmountOfDaysInAYear(const dateYear Year);
	static constexpr dateDay GetAmountOfDaysInAMonth(const dateYear Year, const eMonth Month);
	static constexpr bool IsLeapYear(const dateYear Year);

	bool ValidateDateCorrectness(const dateYear Year, const unsigned int Month,const dateDay Day) const;
	constexpr bool ValidateMonthCorrectness(const unsigned int Month) const;
	bool ValidateDateCorrectness(const dateYear Year, const eMonth Month, const dateDay Day) const;
	dateYear m_year = 0;
	eMonth m_month = eMonth::January;
	dateDay m_day = 0;
};