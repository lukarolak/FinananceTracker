#include <Tests/ReadOneTimePayment/ReadOneTimePayment.h>
#include <FileIO/JsonReader.h>
#include <Error/Error.h>
#include <Data/Payment/OneTimePayment/IO/IO_OneTimePayment.h>
#include <Helper/PathOfExe.h>
bool ReadOneTimePaymentTest()
{
    std::wstring exePath = GetExePathInstance().GetExePath();
    exePath.append(L"\\..\\..\\Code\\Tests\\ReadOneTimePayment\\Data.json");

    const auto& data_wrapper = ReadJson(exePath);

    if (data_wrapper.has_value() == false)
    {
        AssertNoCrash("Data document can't be read");
        return false;
    }

    const auto& data = data_wrapper.value();
    const auto OneTimePaymentsExist = data.HasMember("OneTimePayments");

    if (OneTimePaymentsExist == false)
    {
        AssertNoCrash("Data document does not contains one time payments");
        return false;
    }

    const auto& data_OneTimePayments = data["OneTimePayments"];
    if (data_OneTimePayments.IsArray() == false)
    {
        AssertNoCrash("OneTimePayment in unexpected type");
        return false;
    }

    const auto& data_OneTimePaymentArray = data_OneTimePayments.GetArray();
    for (const auto& data_OneTimePayment : data_OneTimePaymentArray)
    {
        std::optional<OneTimePayment> oneTimePayment = IO_OneTimePayment::ReadData(data_OneTimePayment["OneTimePayment"]);
        if (oneTimePayment.has_value() == false)
        {
            AssertNoCrash("Failed to create OneTimePayment object");
            return false;
        }
    }
    
    return true;
}
