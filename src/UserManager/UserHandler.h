#ifndef TODO_USERHANDLER_H
#define TODO_USERHANDLER_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils.h"


class UserHandler {
private:
    Utils util;
    std::string connection_string = util.getEnvironmentVariableConnectionString();
public:
    bool check_connection();
    int create_user(std::string user_name,std::string password);
};


#endif //TODO_USERHANDLER_H
