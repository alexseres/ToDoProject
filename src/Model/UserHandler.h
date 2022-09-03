#ifndef TODO_USERHANDLER_H
#define TODO_USERHANDLER_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils/Utils.h"
#include "User.h"
#include "../Data/SQL_Operations.h"


class UserHandler {
private:
    SQL_Operations sql_manager;
public:
    int create_user(std::string user_name,std::string password, std::string salt);
    User get_user(std::string user_name, std::string password, std::string salt);
};


#endif //TODO_USERHANDLER_H
