#pragma once
#include <Data/Time/DateAndTime.h>
class OneTimePayment
{
public:
	void LoadData();
	void SaveData();
private:
	DateAndTime m_DateAndTime;
};