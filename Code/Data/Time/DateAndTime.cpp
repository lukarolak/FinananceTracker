#include "DateAndTime.h"

void DateAndTime::SetDateAndTime(const Date& DateIn, const Time TimeIn)
{
    m_Date.SetDate(DateIn);
    m_Time.SetTime(TimeIn);
}
