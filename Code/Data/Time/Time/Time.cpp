#include <Data/Time/Time/Time.h>
#include <cmath>
#include <Error/Error.h>
auto Time::GetHours() const
{
	return m_hours;
}

auto Time::GetMinutes() const
{
	return m_minutes;
}

auto Time::GetSeconds() const
{
	return m_seconds;
}

unsigned int Time::GetTimeInSeconds() const
{
	return m_hours*60*60 + m_minutes*60 + m_seconds;
}

std::string Time::GetTimeStamp() const
{
	std::string timestamp;
	timestamp.append(ConvertToString(m_hours));
	timestamp.append(":");
	timestamp.append(ConvertToString(m_minutes));
	timestamp.append(":");
	timestamp.append(ConvertToString(m_seconds));

	return timestamp;
}

bool Time::operator<(const Time& rhv) const
{
	if (m_hours < rhv.GetHours())
	{
		if (m_minutes < rhv.GetMinutes())
		{
			if (m_seconds < rhv.GetSeconds())
			{
				return true;
			}
		}
	}
	return false;
}

bool Time::operator>(const Time& rhv) const
{
	return rhv < *this;
}

void Time::SetTimeInSeconds(unsigned int Seconds)
{
	m_seconds = Seconds % 60;
	const auto secondsStripped = static_cast<const unsigned int>(std::floor(static_cast<float>(Seconds) / static_cast<float>(60)));
	m_minutes = secondsStripped % 60;
	const auto minutesStripped = static_cast<const unsigned int>(std::floor(static_cast<float>(secondsStripped) / static_cast<float>(60)));
	m_hours = minutesStripped;

	if (ValidateTimeCorectness(m_hours, m_minutes, m_seconds) == false)
	{
		Assert("Seconds entered are more than 24 hrs");
	}
}

void Time::AddTimeInSeconds(const unsigned int Seconds)
{
	SetTimeInSeconds(GetTimeInSeconds() + Seconds);
}

void Time::SetTime(const Time& TimeIn)
{
	m_hours = TimeIn.GetHours();
	m_minutes = TimeIn.GetMinutes();
	m_seconds = TimeIn.GetSeconds();
}

bool Time::SetTime(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds)
{
	bool success = false;
	if (ValidateTimeCorectness(Hours, Minutes, Seconds))
	{
		m_hours = Hours;
		m_minutes = Minutes;
		m_seconds = Seconds;
		success = true;
	}
	return success;
}

bool Time::ValidateTimeCorectness(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds) const
{
	if (Hours > 24)
		return false;

	if (Minutes > 60)
		return false;

	if (Seconds > 60)
		return false;

	return true;
}

std::string Time::ConvertToString(unsigned int number) const
{
	std::string text;
	for (int i = 1; i >= 0; i--)
	{
		if (m_hours < i * 10)
		{
			text.append("0");
		}
	}
	text.append(std::to_string(m_hours));
}
