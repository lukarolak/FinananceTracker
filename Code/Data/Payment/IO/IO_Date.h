#include <optional>
#include <Data/Time/DateAndTime.h>
#include <string>
class IO_Date
{
public:
	std::optional<DateAndTime> ReadDateAndTime(std::string DateAndTimeIn);
private:

};