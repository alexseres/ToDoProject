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
    std::string password;
    vector<Table> tables;

public:
    User(std::string UUID, std::string userName, std::string hashedValue, std::string _salt, std::string _password, vector<Table> _tables):tables(_tables){
        uuid= UUID;
        user_name = userName;
        hashed_value = hashedValue;
        salt = _salt;
        password = _password;
    }
//    User& operator =(const User& other){
//        return *this;
//    }

    std::string get_uuid(){return uuid;};
    std::string get_name(){return user_name;};
    std::string get_hashed_value(){return hashed_value;};
    std::string get_salt(){return salt;};
    std::string get_password(){return password;};



    vector<Table>& get_tables() { return tables;}

};
