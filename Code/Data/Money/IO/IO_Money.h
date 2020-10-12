#pragma once
#include <Data/Money/Money.h>
#include <optional>
#include <FileIO/JsonReader.h>

namespace IO_Money
{
	std::optional<Money> ReadData(const rapidjson::Value& Data);
	void WriteData(const Money& ObjectIn);
};