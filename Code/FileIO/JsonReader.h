#pragma once
#include <string>
#include <API/rapidjson/document.h>
#include <optional>
std::optional<rapidjson::Document> ReadJson(const std::string& path);