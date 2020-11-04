#pragma once
#include <optional>
#include <Data/Time/Time/Time.h>
#include <FileIO/JsonIO.h>

namespace IO_Time
{
	std::optional<Time> ReadData(const rapidjson::Value& Data);
	void WriteData(const Time& ObjectIn);
};