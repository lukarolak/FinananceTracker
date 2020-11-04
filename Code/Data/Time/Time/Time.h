#pragma once

class Time
{
public:
	bool operator< (const Time& rhv) const;
	bool operator> (const Time& rhv) const;

	void SetTimeInSeconds(unsigned int Seconds);
	void AddTimeInSeconds(const unsigned int Seconds);

	void SetTime(const Time& TimeIn);
	bool SetTime(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds);
	auto GetHours() const;
	auto GetMinutes() const;
	auto GetSeconds() const;
	unsigned int GetTimeInSeconds() const;
private:
	bool ValidateTimeCorectness(const unsigned int Hours, const unsigned int Minutes, const unsigned int Seconds) const;

	unsigned int m_hours = 0;
	unsigned int m_minutes = 0;
	unsigned int m_seconds = 0;
};