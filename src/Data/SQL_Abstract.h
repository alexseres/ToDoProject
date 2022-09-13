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
    std::string connection_string = Utils::getEnvironmentVariableConnectionString();

public:
    virtual bool check_connection(pqxx::connection& connection_object) = 0;
    virtual int insert_data(std::string statement) = 0;
    virtual pqxx::result get_data(std::string statement) = 0;
    virtual std::string get_connection_string(){return connection_string;}
    virtual ~SQL_Abstract() {}
};


#endif //TODOPROJECT_SQL_ABSTRACT_H
