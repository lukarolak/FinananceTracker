#pragma once
#include <Data/Time/Date/Date.h>
#include <Data/Time/Time/Time.h>
class DateAndTime
{
public:
	void SetDateAndTime(const Date& DateIn, const Time TimeIn);
private:
	Date m_Date;
	Time m_Time;
};
