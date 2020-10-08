#include "Time.h"

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
