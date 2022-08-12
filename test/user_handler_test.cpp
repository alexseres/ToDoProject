#include <iostream>
#include <gtest/gtest.h>
#include "../src/UserManager/UserHandler.h"


TEST(UserHandlerTest, check_connection){
    UserHandler uh;
    bool result = uh.create_user();

    // Expect equality.
    EXPECT_EQ(1, 0);
}