#ifndef TODO_USERHANDLER_H
#define TODO_USERHANDLER_H
#include <iostream>
#include <pqxx/pqxx>
#include "../Utils/Utils.h"
#include "User.h"
#include "Table.h"
#include "Card.h"
#include "../Data/SQL_Operations.h"


class UserHandler {
private:
    SQL_Operations sql_manager;
public:
    int create_user(std::string user_name,std::string password, std::string salt);
    User get_user(std::string user_name, std::string password, std::string salt);
    void add_table(std::string table_name, std::string user_uuid);
    void get_tables(std::string user_uuid, std::vector<Table> &tables);
    void get_cards(std::string table_uuid, std::vector<Card> &cards);
    void add_card_for_table(std::string table_uuid, std::string card_name);
};


#endif //TODO_USERHANDLER_H
