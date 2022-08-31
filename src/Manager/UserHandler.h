#ifndef TODO_USERHANDLER_H
#define TODO_USERHANDLER_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils.h"
#include "../Model/User.h"
#include "SQL_Operations.h"


class UserHandler {
private:
    std::string connection_string = Utils::getEnvironmentVariableConnectionString();
    SQL_Operations sql_manager;
public:
    bool check_connection(pqxx::connection& connection_object);
    int create_user(std::string user_name,std::string password, std::string salt);
    int get_user(std::string user_name,std::string password, std::string salt);


};


#endif //TODO_USERHANDLER_H
