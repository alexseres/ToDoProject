#pragma once
#include <iostream>
#include <vector>
#include "Table.h"
using namespace std;

class User {
private:
    std::string uuid;
    std::string user_name;
    std::string hashed_value;
    std::string salt;
    vector<Table> tables;

public:
    User(std::string UUID, std::string userName, std::string hashedValue, std::string _salt, vector<Table> _tables):tables(_tables){
        uuid= UUID;
        user_name = userName;
        hashed_value = hashedValue;
        salt = _salt;
    }
    vector<Table> get_tables() { return tables;}

};
