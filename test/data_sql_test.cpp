#include <iostream>
#include "gtest/gtest.h"
#include "SQL_Operations.h"


TEST(SQL_Operations_Tests, check_connection){
    SQL_Operations sql;
    bool expected = true;
    pqxx::connection connection_object(sql.get_connection_string());
    bool res = sql.check_connection(connection_object);


    EXPECT_EQ(expected, res);
}
