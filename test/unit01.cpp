#include <gtest/gtest.h>
#include "json_lib.h"

class myTests : public ::testing::Test {
};

TEST_F(myTests, test_parse_simple) {
    Json_Lib::JsonValue v;  
    Json_Lib::JsonParser parser;

    // parse success cases
    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_OK, parser.parse(v, "null"));
    EXPECT_EQ(Json_Lib::JsonType::JSON_NULL, v.getType());

    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_OK, parser.parse(v, "true"));
    EXPECT_EQ(Json_Lib::JsonType::JSON_BOOL, v.getType());

    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_OK, parser.parse(v, "false"));
    EXPECT_EQ(Json_Lib::JsonType::JSON_BOOL, v.getType());

    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_OK, parser.parse(v, "              \n\t \tfalse"));
    EXPECT_EQ(Json_Lib::JsonType::JSON_BOOL, v.getType());


    // parse invalid cases
    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_ROOT_NOT_SINGULAR, parser.parse(v, "null true"));

    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_EXPECT_VALUE, parser.parse(v, "  \n"));

    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_EXPECT_VALUE, parser.parse(v, ""));


    EXPECT_EQ(Json_Lib::JsonParserRet::PARSE_INVALID_VALUE, parser.parse(v, "  fadfasn"));

}