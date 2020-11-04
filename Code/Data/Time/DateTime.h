#pragma once
#include <Data/Time/Date/Date.h>
#include <Data/Time/Time/Time.h>
#include <optional>
#include <string>
class DateTime
{
public:
	DateTime() = default;
	DateTime(const DateTime& DateTimeIn);
	DateTime(const Date& DateIn, const Time& TimeIn);
	bool operator< (const DateTime& rhv) const;
	bool operator> (const DateTime& rhv) const;
	DateTime& operator+ (const DateTime& rhv);

	void SetDateTimeInSeconds(const unsigned long long Seconds);
	static const DateTime GetCurrentDateTime();
	const unsigned long long GetDateTimeInSeconds() const;
	const Date& GetDate() const;
	const Time& GetTime() const;
	const std::string GetTimeStamp() const;
private:
	Date m_Date;
	Time m_Time;
};