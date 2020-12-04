#include <Data/Time/Utilities/DateTimeUtilities.h>
#include <Data/Time/Date/Utilities/DateUtilities.h>

DateTime TimeUtilities::ReduceByDays(const DateTime& DateTimeIn, const dateDay DayAmount)
{
	const auto& daysSince0 = DateTimeIn.GetDate().GetDateInDays()- DayAmount;

	DateTime DateTimeOut;
	DateTimeOut.SetDateTimeInDays(daysSince0);
	return DateTimeOut;
}
