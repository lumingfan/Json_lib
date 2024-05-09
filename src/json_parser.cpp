#include <string>
#include <sstream>

#include "json_lib.h"


namespace Json_Lib {
    JsonParser::JsonParser() {

    }

    JsonParser::JsonParser(const std::string &file_name) {

    }


    JsonParserRet JsonParser::parse(JsonValue &val) {

    }

    JsonParserRet JsonParser::parse(JsonValue &val, const std::string &json) {
        std::istringstream is(json);
        std::string json_val;  

        if (is >> json_val) {
            if (is >> json_val) {
                return JsonParserRet::PARSE_ROOT_NOT_SINGULAR;
            }

            if (!JsonValue::CheckValidJsonValue(json_val)) {
                return JsonParserRet::PARSE_INVALID_VALUE;
            } 

            val.set(json_val);
            return JsonParserRet::PARSE_OK;
        } 
        
        return JsonParserRet::PARSE_EXPECT_VALUE;
    }



} // namespace Json_Lib

