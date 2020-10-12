#pragma once
#include <string>
#include <API/rapidjson/document.h>
#include <optional>
#include <API/rapidjson/writer.h>
#include <API/rapidjson/stringbuffer.h>
#include <API/rapidjson/istreamwrapper.h>
#include <fstream>
#include <Error/Error.h>

template <typename pathType>
std::optional<rapidjson::Document> ReadJson(const pathType& path)
{
    std::ifstream stream(path);
    if (stream.fail())
    {
        AssertNoCrash("Could not open file: ");
        AssertNoCrash(path);
        return {};
    }
    rapidjson::IStreamWrapper streamRapidJson(stream);
    
    rapidjson::Document document;
    document.ParseStream(streamRapidJson);
    return document;
}
