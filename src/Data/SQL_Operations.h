#ifndef TODOPROJECT_SQL_OPERATIONS_H
#define TODOPROJECT_SQL_OPERATIONS_H
#include <iostream>
#include <pqxx/pqxx>

#include "../Utils/Utils.h"


class SQL_Operations {
private:
    std::string connection_string = Utils::getEnvironmentVariableConnectionString();

public:
    bool check_connection(pqxx::connection& connection_object);
    int insert_data(std::string statement);
    pqxx::result get_data(std::string statement);
    std::string get_connection_string(){return connection_string;}
};


#endif //TODOPROJECT_SQL_OPERATIONS_H
