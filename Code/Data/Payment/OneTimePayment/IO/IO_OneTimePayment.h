#pragma once
#include <Data/Payment/OneTimePayment/OneTimePayment.h>
#include <string>
#include <FileIO/JsonIO.h>
#include <optional>

namespace IO_OneTimePayment
{
	std::optional<OneTimePayment> ReadData(const rapidjson::Value& Data);
	void WriteData(const OneTimePayment& ObjectIn);
};