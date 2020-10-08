#include <Tests/Tests.h>
#include <Tests/ReadOneTimePayment/ReadOneTimePayment.h>
#include <Error/Error.h>
bool RunAllTests()
{
    if (ReadOneTimePaymentTest() == false)
    {
        AssertNoCrash("ReadOneTimePaymentTest failed");
        return false;
    }

    return true;
}
