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
    int view_id;
public:
    Table(std::string userId, std::string tableId, std::string name, vector<Card> _cards):user_id(userId), table_id(tableId), table_name(name), cards(_cards){}
    std::string get_table_name() { return table_name; }
    vector<Card>& get_cards(){ return cards;}
    void set_view_id(int id){view_id = id;}
    int get_view_id(){ return view_id; }
    std::string get_table_id(){ return table_id;}
};
#endif //TODOPROJECT_TABLE_H
