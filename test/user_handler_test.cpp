#include <iostream>
#include "gtest/gtest.h"
#include "../src/Manager/UserHandler.h"



TEST(UserHandlerTest, check_connection){
    // UserHandler uh;
    // bool result = uh.check_connection();

    // Expect equality.
    EXPECT_EQ(1, 0);
}

TEST(UserHandlerTest, check_create_user){
    UserHandler uh;
    std::string user_name = "Alex";
    std::string password = "valami";
    std::string salt = "so";

    int num1 = uh.create_user(user_name, password, salt);
    int num2 = uh.get_user(user_name, password, salt);
}

TEST(UserHandlerTest, get_user){
    UserHandler uh;
    std::string user_name = "Alex";
    std::string password = "valami";
    std::string salt = "so";

    int num2 = uh.get_user(user_name, password, salt);
}