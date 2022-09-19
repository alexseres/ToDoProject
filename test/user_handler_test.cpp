#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "UserHandler.h"


TEST(UserHandlerTest, get_tables_test){
    int expected_tables_siz = 3;
    SQL_Abstract *sql = new SQL_Operations;
    UserHandler handler(sql);
    std::string uuid = "680e8c2c-3bb7-463c-a6c7-5607fe1ea247";
    std::vector<Table> tables;
    int expected_tables_size = 3;
    handler.get_tables(uuid, tables);

    EXPECT_EQ(expected_tables_size, tables.size());

}

TEST(UserHandlerTest, get_user){
//    UserHandler uh;
    std::string user_name = "Alex";
    std::string password = "valami";
    std::string salt = "so";

//    int num2 = uh.get_user(user_name, password, salt);
}