#ifndef TODOPROJECT_SQL_OPERATIONS_MOCK_H
#define TODOPROJECT_SQL_OPERATIONS_MOCK_H
#include <iostream>
#include <pqxx/pqxx>
#include "gmock/gmock.h"
#include "../src/Data/SQL_Abstract.h"

class SQL_Operations_Mock : public SQL_Abstract{
public:

    MOCK_METHOD(int, insert_data, (std::string statement), (override));
    MOCK_METHOD(pqxx::result, get_data, (std::string statement), (override));
//    MOCK_METHOD(bool, check_connection, (), (override));
};


#endif //TODOPROJECT_SQL_OPERATIONS_MOCK_H
