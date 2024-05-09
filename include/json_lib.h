#pragma once

#include <string>

namespace Json_Lib {
enum class JsonType {
    JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT
};

enum class JsonParserRet {
    PARSE_OK, PARSE_EXPECT_VALUE, PARSE_ROOT_NOT_SINGULAR, PARSE_INVALID_VALUE
};

class JsonParser;

class JsonValue {
friend class JsonParser;

public: 
    JsonType getType();
    static bool CheckValidJsonValue(const std::string &val);

private:
    void set(const std::string &val);

    JsonType _type;
};


class JsonParser {
public:
    JsonParser();
    JsonParser(const std::string &file_name);

    JsonParserRet parse(JsonValue &val);
    JsonParserRet parse(JsonValue &val, const std::string &json);
};

} // namespace Json_Lib