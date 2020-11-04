#pragma once
#include <string>
#include <rapidjson/document.h>
#include <optional>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>
#include <Error/Error.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/writer.h>

template <typename pathType>
std::optional<rapidjson::Document> ReadJson(const pathType& Path)
{
    std::ifstream stream(Path);
    if (stream.fail())
    {
        return {};
    }
    rapidjson::IStreamWrapper streamRapidJson(stream);
    
    rapidjson::Document document;
    document.ParseStream(streamRapidJson);
    return document;
}

template <typename pathType>
bool WriteJson(const pathType& Path, rapidjson::Document& DocumentIn)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    DocumentIn.Accept(writer);

    std::string jsonStr = buffer.GetString();

    std::ofstream file;
    file.open(Path);
    if (file.fail())
    {
        return false;
    }
    file << jsonStr;
    file.close();

    return true;
}
