#include <Tests/FetchDataFromPayPal/FetchDataFromPaypalTest.h>
#include <FetchDataFromWeb/PayPal/PayPal.h>
bool FetchDataFromPaypalTest()
{
    PayPal payPal;
    payPal.Initialize();
    payPal.GetPayments();
    return false;
}
