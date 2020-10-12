#pragma once
#include <Data/Time/Date/Date.h>
#include <Data/Time/Time/Time.h>
#include <string>
#include <Data/Money/Money.h>

class OneTimePayment
{
public:
	void SetDate(const Date& Date);
	void SetTime(const Time& Time);
	void SetMoney(const Money& Money);
private:
	Date m_Date;
	Time m_Time;
	Money m_Money;
};