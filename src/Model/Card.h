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
public:
    Card(std::string tableUuid, std::string cardUuid, std::string desc):descripton(desc), card_uuid(cardUuid), table_uuid(tableUuid){};
};


#endif //TODOPROJECT_CARD_H
