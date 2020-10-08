#include <Data/Time/Date/IO/IO_Date.h>
#include <Error/Error.h>
#include <Helper/CharToInt.h>

std::optional<Date> IO_Date::ReadData(const rapidjson::Value& Data)
{
    if (Data.IsString() == false)
    {
        AssertNoCrash("Date field is of an unexpected type");
        return {};
    }

    if (Data.GetStringLength() != 10)
    {
        AssertNoCrash("String time of unsupported length");
        return {};
    }

    const auto& date_data = Data.GetString();
    const unsigned int day = CharToInt(date_data[0]) * 10 + CharToInt(date_data[1]);
    const unsigned int month = CharToInt(date_data[3]) * 10 + CharToInt(date_data[4]);
    const unsigned year = CharToInt(date_data[6]) * 1000 + CharToInt(date_data[7]) * 100 + CharToInt(date_data[8]) * 10 + CharToInt(date_data[9]);

    Date date;
    const auto DateSet = date.SetDate(year, month, day);
    if (DateSet == false)
    {
        AssertNoCrash("Can't set date");
        return {};
    }

    return date;
}
