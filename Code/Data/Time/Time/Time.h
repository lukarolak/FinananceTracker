#pragma once

class Time
{
public:
	void SetTime(const Time& TimeIn);
	bool SetTime(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds);
	auto GetHours() const;
	auto GetMinutes() const;
	auto GetSeconds() const;
private:
	bool ValidateTimeCorectness(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds) const;

	unsigned int m_hours = 0;
	unsigned int m_minutes = 0;
	unsigned int m_seconds = 0;
};