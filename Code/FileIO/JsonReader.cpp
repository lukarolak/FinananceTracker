#include <FileIO/JsonReader.h>
#include <API/rapidjson/writer.h>
#include <API/rapidjson/stringbuffer.h>

#include <API/rapidjson/istreamwrapper.h>
#include <fstream>
#include <Error/Error.h>

std::optional<rapidjson::Document> ReadJson(const std::string& path)
{
    std::ifstream stream(path);
    if (stream.fail())
    {
        AssertNoCrash("Could not open file: " + path);
        return {};
    }
    rapidjson::IStreamWrapper streamRapidJson(stream);

    rapidjson::Document document;
    document.ParseStream(streamRapidJson);
    return document;
}
