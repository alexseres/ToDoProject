#ifndef TODO_USERHANDLER_H
#define TODO_USERHANDLER_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils.h"


class UserHandler {
private:
    Utils util;
public:

    bool check_connection();
    int create_user();
};


#endif //TODO_USERHANDLER_H
