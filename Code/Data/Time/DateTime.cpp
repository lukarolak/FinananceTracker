#include <Data/Time/DateTime.h>
#include <Error/Error.h>
#include <chrono>
#include <cmath>

DateTime::DateTime(const DateTime& DateTimeIn)
    :m_Date(DateTimeIn.m_Date), m_Time(DateTimeIn.m_Time)
{
}

DateTime::DateTime(const Date& DateIn, const Time& TimeIn)
    :m_Date(DateIn), m_Time(TimeIn)
{
}

void DateTime::SetDateTimeInSeconds(const unsigned long long Seconds)
{
    constexpr auto secondsInADay = 24 * 60 * 60;
    const auto amountOfDays = static_cast<const unsigned int>(std::floor(static_cast<float>(Seconds) / static_cast<float>(secondsInADay)));
    
    m_Date.SetDateInDays(amountOfDays);
    m_Time.SetTimeInSeconds(Seconds % secondsInADay);
}

void DateTime::SetDateTimeInDays(const dateDay DayAmount)
{
    m_Date.SetDateInDays(DayAmount);
    m_Time.SetTime(0, 0, 0);
}

const DateTime DateTime::GetCurrentDateTime()
{
    const auto currentTime = std::chrono::system_clock::now();
    time_t rawtime;
    struct tm ptm;

    time(&rawtime);
    gmtime_s(&ptm, &rawtime);

    Date date;
    bool sucess = date.SetDate(ptm.tm_year + 1900, ptm.tm_mon, ptm.tm_mday);
    if (sucess == false)
    {
        Assert("Can't get current date");
    }

    Time time;
    sucess = time.SetTime(ptm.tm_hour, ptm.tm_min, ptm.tm_sec);
    if (sucess == false)
    {
        Assert("Can't get current time");
    }

    DateTime dateTime(date, time);
    return dateTime;
}

const unsigned long long DateTime::GetDateTimeInSeconds() const
{
    const auto dateInSeconds = m_Date.GetDateInSeconds();
    const auto timeInSeconds = m_Time.GetTimeInSeconds();
    return dateInSeconds + timeInSeconds;
}

const Date& DateTime::GetDate() const
{
    return m_Date;
}

const Time& DateTime::GetTime() const
{
    return m_Time;
}

const std::string DateTime::GetTimeStamp() const
{
    return m_Date.GetTimeStamp() + "T" + m_Time.GetTimeStamp() + "+0000";
}

bool DateTime::operator<(const DateTime& rhv) const
{
    if (m_Date < rhv.GetDate())
    {
        if (m_Time < rhv.GetTime())
        {
            return true;
        }
    }
    return false;
}

bool DateTime::operator>(const DateTime& rhv) const
{
    return rhv < *this;
}

DateTime& DateTime::operator+(const DateTime& rhv)
{
    const auto totalTime = m_Time.GetTimeInSeconds() + rhv.m_Time.GetTimeInSeconds();
    const auto totalTimeOverflowInDays = static_cast<const unsigned int>(std::floor(static_cast<float>(totalTime) / static_cast<float>(24*60*60)));

    const unsigned int timeWithoutDays = totalTime - (totalTimeOverflowInDays * 24 * 60 * 60);
    m_Time.AddTimeInSeconds(timeWithoutDays);
    m_Date.AddDateInDays(totalTimeOverflowInDays);

    return *this;
}
