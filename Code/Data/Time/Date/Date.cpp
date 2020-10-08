#include <Data/Time/Date/Date.h>
#include <Error/Error.h>

auto Date::GetYear() const
{
	return m_year;
}

auto Date::GetMonth() const
{
	return m_month;
}

auto Date::GetDay() const
{
	return m_day;
}

void Date::SetDate(const Date& DateIn)
{
	m_year = DateIn.GetYear();
	m_month = DateIn.GetMonth();
	m_day = DateIn.GetDay();
}

bool Date::SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day)
{
	bool success = false;
	if (ValidateDateCorrectness(Year, Month, Day))
	{
		m_year = Year;
		m_month = static_cast<eMonth>(Month);
		m_day = Day;
		success = true;
	}
	return success;
}

bool Date::ValidateDateCorrectness(const unsigned int Year, const unsigned int Month, const unsigned int Day) const
{
	if (Month < static_cast<int>(eMonth::January) && Month > static_cast<int>(eMonth::December))
		return false;

	unsigned int dayInAMonth = 0;

	switch (static_cast<eMonth>(Month))
	{
	case eMonth::January:
		dayInAMonth = 31;
		break;
	case eMonth::February:
		if (IsLeapYear(Year))
			dayInAMonth = 28;
		else
			dayInAMonth = 29;
		break;
	case eMonth::March:
		dayInAMonth = 31;
		break;
	case eMonth::April:
		dayInAMonth = 30;
		break;
	case eMonth::May:
		dayInAMonth = 31;
		break;
	case eMonth::June:
		dayInAMonth = 30;
		break;
	case eMonth::July:
		dayInAMonth = 31;
		break;
	case eMonth::August:
		dayInAMonth = 31;
		break;
	case eMonth::September:
		dayInAMonth = 30;
		break;
	case eMonth::October:
		dayInAMonth = 31;
		break;
	case eMonth::November:
		dayInAMonth = 30;
		break;
	case eMonth::December:
		dayInAMonth = 31;
		break;
	default:
		AssertNoCrash("InvalidMonth");
		dayInAMonth = 0;
		break;
	}

	const bool DayWithinMaximumDaysInAMonth = dayInAMonth >= Day;
	return DayWithinMaximumDaysInAMonth;
}

bool Date::IsLeapYear(const unsigned int Year) const
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
