#pragma once
#ifndef TODOPROJECT_CARD_H
#define TODOPROJECT_CARD_H
#include <iostream>
#include <vector>
using namespace std;


class Card {
private:
    std::string table_uuid;
    std::string card_uuid;
    std::string descripton;
    int view_id;
public:
    Card(std::string tableUuid, std::string cardUuid, std::string desc):descripton(desc), card_uuid(cardUuid), table_uuid(tableUuid){};
    string get_description(){ return descripton; }
    void set_view_id(int id){view_id = id;}
    int get_view_id(){ return view_id; }
    std::string get_card_id(){ return card_uuid; }
    std::string get_table_id(){ return table_uuid; }

//    Card& operator=(const Card& c){
//        return *this;
//    }
//    Card(const Card& c){
//        descripton = c.descripton;
//        card_uuid = c.card_uuid;
//        table_uuid = c.table_uuid;
//    }

};


#endif //TODOPROJECT_CARD_H
