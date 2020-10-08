#include <Tests/ReadOneTimePayment/ReadOneTimePayment.h>
#include <FileIO/JsonReader.h>
#include <Error/Error.h>
bool ReadOneTimePaymentTest()
{
    const auto& optional_data = ReadJson("C:\\Users\\Luka\\source\\repos\\FinananceTracker\\Code\\Tests\\ReadOneTimePayment\\Data.json");

    if (optional_data.has_value() == false)
    {
        AssertNoCrash("Data document can't be read");
        return false;
    }

    const auto& data = optional_data.value();
    return false;
}
