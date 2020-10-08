#pragma once
#include <Data/Time/Date/Date.h>
#include <optional>
#include <FileIO/JsonReader.h>

namespace IO_Date
{
	std::optional<Date> ReadData(const rapidjson::Value& Data);
	void WriteData(const Date& ObjectIn);
};