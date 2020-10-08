#pragma once
#include <Data/Time/Date/Date.h>
#include <Data/Time/Time/Time.h>
#include <string>
class OneTimePayment
{
public:
	void SetDate(const Date& Date);
	void SetTime(const Time& Time);
private:
	Date m_Date;
	Time m_Time;
};