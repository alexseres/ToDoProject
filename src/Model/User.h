#pragma once
#include <iostream>

class User {
private:
    std::string uuid;
    std::string user_name;
    std::string hashed_value;
    std::string salt;
public:
    User(std::string UUID, std::string userName, std::string hashedValue, std::string salt) {
        uuid= UUID;
        user_name = userName;
        hashed_value = hashedValue;
        salt = salt;
    }
};
