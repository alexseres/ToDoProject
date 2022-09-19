//
// Created by Alex Seres on 13/09/2022.
//

#ifndef TODOPROJECT_SQL_ABSTRACT_H
#define TODOPROJECT_SQL_ABSTRACT_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils/Utils.h"


class SQL_Abstract {
private:

public:
    virtual bool check_connection(pqxx::connection &connection_object) = 0;
    virtual int insert_data(std::string statement) = 0;
    virtual pqxx::result get_data(std::string statement) = 0;
    virtual ~SQL_Abstract() = default;
};


#endif //TODOPROJECT_SQL_ABSTRACT_H
