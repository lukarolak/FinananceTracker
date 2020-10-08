#include <Data/Payment/OneTimePayment/IO/IO_OneTimePayment.h>
#include <Error/Error.h>
#include <Data/Time/Date/IO/IO_Date.h>
#include <Data/Time/Time/IO/IO_Time.h>
std::optional<OneTimePayment> IO_OneTimePayment::ReadData(const rapidjson::Value& Data)
{
    OneTimePayment oneTimePayment;

    if (Data.HasMember("Date") == false)
    {
        AssertNoCrash("\"Date\" field is not present in one time payment");
        return {};
    }

    const auto& date_wrapper =  IO_Date::ReadData(Data["Date"]);
    if (date_wrapper.has_value() == false)
    {
        AssertNoCrash("Can't get a date from OneTimePayment data");
        return {};
    }

    oneTimePayment.SetDate(date_wrapper.value());

    if (Data.HasMember("Time") == false)
    {
        AssertNoCrash("\"Time\" field is not present in one time payment");
        return {};
    }

    const auto& time_wrapper = IO_Time::ReadData(Data["Time"]);
    if (time_wrapper.has_value() == false)
    {
        AssertNoCrash("Can't get time from OneTimePayment data");
        return {};
    }

    oneTimePayment.SetTime(time_wrapper.value());

    return oneTimePayment;
}
