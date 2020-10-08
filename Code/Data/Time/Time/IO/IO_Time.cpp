#include <Data/Time/Time/IO/IO_Time.h>
#include <Error/Error.h>
#include <Helper/CharToInt.h>

std::optional<Time> IO_Time::ReadData(const rapidjson::Value& Data)
{
    if (Data.IsString() == false)
    {
        AssertNoCrash("Time field is of an unexpected type");
        return {};
    }

    if (Data.GetStringLength() != 8)
    {
        AssertNoCrash("String time of unsupported length");
        return {};
    }

    const auto& date_data = Data.GetString();
    const unsigned int hours = CharToInt(date_data[0]) * 10 + CharToInt(date_data[1]);
    const unsigned int minutes = CharToInt(date_data[3]) * 10 + CharToInt(date_data[4]);
    const unsigned seconds = CharToInt(date_data[6]) * 10 + CharToInt(date_data[7]);

    Time time;
    const auto timeSet = time.SetTime(hours,minutes,seconds);
    if (timeSet == false)
    {
        AssertNoCrash("Can't set time");
        return {};
    }

    return time;
}
