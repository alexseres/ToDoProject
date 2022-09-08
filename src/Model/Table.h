#pragma once
#ifndef TODOPROJECT_TABLE_H
#define TODOPROJECT_TABLE_H
#include <iostream>
#include "Card.h"

class Table {
private:
    std::string user_id;
    std::string table_id;
    std::string table_name;
    vector<Card> cards;
public:
    Table(std::string userId, std::string tableId, std::string name, vector<Card> _cards):user_id(userId), table_id(tableId), table_name(name), cards(_cards){}
};


#endif //TODOPROJECT_TABLE_H
