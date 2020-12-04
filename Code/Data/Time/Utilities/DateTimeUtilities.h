#pragma once
#include <Data/Time/DateTime.h>

namespace TimeUtilities
{
	DateTime ReduceByDays(const DateTime& DateTimeIn, const dateDay DayAmount);
}