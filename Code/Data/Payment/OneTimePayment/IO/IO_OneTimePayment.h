#pragma once
#include <Data/Payment/OneTimePayment/OneTimePayment.h>
#include <string>
#include <FileIO/JsonReader.h>
#include <optional>

class IO_OneTimePayment
{
	std::optional<OneTimePayment> ReadData(const rapidjson::Document& Data);
	void WriteData(const OneTimePayment& ObjectIn);
};