#pragma once
#include <Data/Time/DateAndTime.h>
#include <string>
class OneTimePayment
{
public:
	bool SetDate(const std::string& Date);
	bool SetTime(const std::string& Time);
private:
	DateAndTime m_DateAndTime;
};