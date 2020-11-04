#pragma once
#include <Data/Time/Date/Months.h>
#include <string>
class Date
{
public:
	bool operator< (const Date& rhv) const;
	bool operator> (const Date& rhv) const;

	void SetDate(const Date& DateIn);
	bool SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	bool SetDate(const unsigned int Year, const eMonth Month, const unsigned int Day);
	void SetDateInDays(unsigned int Days);
	void AddDateInDays(const unsigned int Days);
	unsigned int GetYear() const;
	eMonth GetMonth() const;
	unsigned int GetDay() const;
	unsigned int GetDateInDays() const;
	unsigned long long GetDateInSeconds() const;
	std::string GetTimeStamp() const;
private:
	static constexpr unsigned int GetAmountOfDaysInAYear(const unsigned int Year);
	static constexpr unsigned int GetAmountOfDaysInAMonth(const unsigned int Year, const eMonth Month);
	static constexpr bool IsLeapYear(const unsigned int Year);

	bool ValidateDateCorrectness(const unsigned int Year, const unsigned int Month,const unsigned int Day) const;
	constexpr bool ValidateMonthCorrectness(const unsigned int Month) const;
	bool ValidateDateCorrectness(const unsigned int Year, const eMonth Month, const unsigned int Day) const;
	unsigned int m_year = 0;
	eMonth m_month = eMonth::January;
	unsigned int m_day = 0;
};