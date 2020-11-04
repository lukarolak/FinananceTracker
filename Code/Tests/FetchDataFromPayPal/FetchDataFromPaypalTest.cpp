#include <Tests/FetchDataFromPayPal/FetchDataFromPaypalTest.h>
#include <FetchDataFromWeb/PayPal/PayPal.h>
bool FetchDataFromPaypalTest()
{
    PayPal payPal;
    payPal.GetPayments();
    return false;
}
