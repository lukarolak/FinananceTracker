#include <Data/Time/Date/Date.h>
#include <Error/Error.h>

unsigned int Date::GetYear() const
{
	return m_year;
}

eMonth Date::GetMonth() const
{
	return m_month;
}

unsigned int Date::GetDay() const
{
	return m_day;
}

bool Date::operator<(const Date& rhv) const
{
	if (m_year < rhv.GetYear())
	{
		if (m_month < rhv.GetMonth())
		{
			if (m_day < rhv.GetDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>(const Date& rhv) const
{
	return rhv < *this;
}

void Date::SetDate(const Date& DateIn)
{
	m_year = DateIn.GetYear();
	m_month = DateIn.GetMonth();
	m_day = DateIn.GetDay();
}

bool Date::SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day)
{
	if (ValidateMonthCorrectness(Month))
	{
		return SetDate(Year, static_cast<eMonth>(Month), Day);
	}
	return false;
}

bool Date::SetDate(const unsigned int Year, const eMonth Month, const unsigned int Day)
{
	bool success = false;
	if (ValidateDateCorrectness(Year, Month, Day))
	{
		m_year = Year;
		m_month = Month;
		m_day = Day;
		success = true;
	}
	return success;
}

void Date::SetDateInDays(unsigned int Days)
{
	unsigned int year = 0;
	int daysStrippedOfYears = Days;
	bool strippingYears = false;
	do
	{
		strippingYears = false;
		if (IsLeapYear(year))
		{
			if (daysStrippedOfYears - 366 > 0)
			{
				strippingYears = true;
				daysStrippedOfYears -= 366;
				year++;
			}
		}
		else
		{
			if (daysStrippedOfYears - 365 > 0)
			{
				strippingYears = true;
				daysStrippedOfYears -= 365;
				year++;
			}
		}
	} while (strippingYears);

	m_year = year;

	eMonth month = eMonth::January;
	bool strippingMonths = false;
	int daysStrippedOfYearsAndMonths = daysStrippedOfYears;
	do
	{
		strippingMonths = false;
		const auto& amountOfDaysInAMonth = GetAmountOfDaysInAMonth(m_year, month);
		if (daysStrippedOfYearsAndMonths - static_cast<int>(amountOfDaysInAMonth) > 0)
		{
			daysStrippedOfYearsAndMonths -= amountOfDaysInAMonth;
			strippingMonths = true;
			month++;
		}
	} while (strippingMonths);

	m_month = month;
	m_day = daysStrippedOfYearsAndMonths;

	if (ValidateDateCorrectness(m_year, m_month, m_day) == false)
	{
		Assert("Can't conver days into Date");
	}

}

void Date::AddDateInDays(const unsigned int Days)
{
	SetDateInDays(GetDateInDays() + Days);
}

unsigned int Date::GetDateInDays() const
{
	unsigned int totalDays = 0;
	totalDays = GetAmountOfDaysInAYear(m_year - 1);
	if (m_month > eMonth::January)
	{
		for (eMonth month = eMonth::January; month <= m_month - 1; month++)
		{
			totalDays += GetAmountOfDaysInAMonth(m_year, month);
		}
	}
	totalDays += m_day;
	return totalDays;
}

unsigned long long Date::GetDateInSeconds() const
{
	const auto dateInDays = GetDateInDays();
	return static_cast<unsigned long long>(dateInDays)*24*60*60;
}

std::string Date::GetTimeStamp() const
{
	Assert("Function not implemented");
	std::string timestamp;
	auto year = m_year;
	return std::to_string(m_year) + "-" + std::to_string(m_month) + std::to_string(m_day);
}

constexpr unsigned int Date::GetAmountOfDaysInAYear(const unsigned int Year)
{
	unsigned int totalDays = 0;
	for (unsigned int year = 0; year <= Year; year++)
	{
		for (eMonth month = eMonth::January; month < eMonth::December; month++)
		{
			totalDays += GetAmountOfDaysInAMonth(year, month);
		}
		totalDays += GetAmountOfDaysInAMonth(year, eMonth::December);
		//Can't convert the if condition into <=, as I can't increment month enum over December
	}

	return totalDays;
}

constexpr unsigned int Date::GetAmountOfDaysInAMonth(const unsigned int Year, const eMonth Month)
{
	switch (Month)
	{
	case eMonth::January:
		return 31;
	case eMonth::February:
		if (IsLeapYear(Year))
			return 29;
		else
			return 28;
	case eMonth::March:
		return 31;
	case eMonth::April:
		return 30;
	case eMonth::May:
		return 31;
	case eMonth::June:
		return 30;
	case eMonth::July:
		return 31;
	case eMonth::August:
		return 31;
	case eMonth::September:
		return 30;
	case eMonth::October:
		return 31;
	case eMonth::November:
		return 30;
	case eMonth::December:
		return 31;
	default:
		Assert("Invalid Month");
		return 0;
	}
}

constexpr bool Date::IsLeapYear(const unsigned int Year)
{
	if (Year % 4 == 0)
	{
		if (Year % 100 == 0)
		{
			if (Year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool Date::ValidateDateCorrectness(const unsigned int Year, const unsigned int Month, const unsigned int Day) const
{
	if(ValidateMonthCorrectness(Month) == false)
		return false;

	return ValidateDateCorrectness(Year, static_cast<eMonth>(Month), Day);
}

constexpr bool Date::ValidateMonthCorrectness(const unsigned int Month) const
{
	return Month >= static_cast<int>(eMonth::January) && Month <= static_cast<int>(eMonth::December);
}

bool Date::ValidateDateCorrectness(const unsigned int Year, const eMonth Month, const unsigned int Day) const
{
	const auto& daysInAMonth = GetAmountOfDaysInAMonth(Year, Month);
	const bool DayWithinMaximumDaysInAMonth = daysInAMonth >= Day;

	return DayWithinMaximumDaysInAMonth;
}