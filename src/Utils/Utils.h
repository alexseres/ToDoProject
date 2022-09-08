#pragma once
#include <iostream>

class Utils {
public:
    static std::string generateUUID();
    std::string static const getEnvironmentVariableConnectionString();
    unsigned long static const hash_password(std::string str);
};