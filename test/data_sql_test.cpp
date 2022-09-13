#include <iostream>
#include "gtest/gtest.h"
#include "SQL_Operations.h"

SQL_Operations sql;
pqxx::connection connection_object(sql.get_connection_string());

TEST(SQL_Operations_Tests, get_data){
    std::string sql_statement = "SELECT * FROM \"users\" WHERE user_name='PP' AND salt='PP';";
    std::string expected_user_name = "PP";
    pqxx::result r = sql.get_data(sql_statement);
    std::string result_user_name = pqxx::to_string(r[0][1].c_str());

    EXPECT_EQ(expected_user_name, result_user_name);
}

TEST(SQL_Operations_Tests, check_connection){
    bool expected = true;
    bool res = sql.check_connection(connection_object);


    EXPECT_EQ(expected, res);
}


//No Insertion Test Taken