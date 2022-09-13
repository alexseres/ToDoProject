//
// Created by Alex Seres on 13/09/2022.
//

#ifndef TODOPROJECT_SQL_OPERATIONS_MOCK_H
#define TODOPROJECT_SQL_OPERATIONS_MOCK_H

#include <pqxx/pqxx>
#include "gmock/gmock.h"
#include "SQL_Abstract.h"

class SQL_Operations_Mock : SQL_Abstract{
    MOCK_METHOD(bool, insert_data, ());
};


#endif //TODOPROJECT_SQL_OPERATIONS_MOCK_H
