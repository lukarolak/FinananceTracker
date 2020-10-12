#include "OneTimePayment.h"

void OneTimePayment::SetDate(const Date& Date)
{
	m_Date.SetDate(Date);
}

void OneTimePayment::SetTime(const Time& Time)
{
	m_Time.SetTime(Time);
}

void OneTimePayment::SetMoney(const Money& Money)
{
	m_Money.SetMoney(Money);
}
