#include <Tests/Tests.h>
#include <Tests/ReadOneTimePayment/ReadOneTimePayment.h>
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
        Log("OneTimePaymentTest succeeded");
        Log("OneTimePaymentTest succeeded");
    }

    return true;
}
