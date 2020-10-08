#include "DateAndTime.h"

void DateAndTime::SetDateAndTime(const std::string& DateAndTime)
{
    int day;
    day = static_cast<int>(DateAndTime[0])*10+ static_cast<int>(DateAndTime[1]);
}

void DateAndTime::SetDateAndTime(const Date& DateIn, const Time TimeIn)
{
    m_Date.SetDate(DateIn);
    m_Time.SetTime(TimeIn);
}
