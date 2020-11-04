#include <Tests/Tests.h>
#include <Tests/ReadOneTimePayment/ReadOneTimePayment.h>
#include <Tests/FetchDataFromPayPal/FetchDataFromPaypalTest.h>
#include <Error/Error.h>
#include <Logging/Logging.h>
bool RunAllTests()
{
    if (ReadOneTimePaymentTest() == false)
    {
        AssertNoCrash("ReadOneTimePaymentTest failed");
        return false;
    }
    else
    {
        Log("OneTimePaymentTest succeeded");
    }

    if (FetchDataFromPaypalTest() == false)
    {
        AssertNoCrash("Fetch data from paypal test failed");
        return false;
    }
    else
    {
        Log("FetchDataFromPaypalTest succeeded");
    }

    return true;
}
