#include "json_lib.h"

namespace Json_Lib {

// static helper function
bool JsonValue::CheckValidJsonValue(const std::string &val) {
    if (val != "null" && val != "false" && val != "true") {
        return false;
    }
    return true;
}


JsonType JsonValue::getType() {
    return this->_type;
}

void JsonValue::set(const std::string &val) {
    if (val == "null") {
        this->_type = JsonType::JSON_NULL;
    } else if (val == "false" || val == "true") {
        this->_type = JsonType::JSON_BOOL;
    } 
}

    

}; // namespace Json_Lib