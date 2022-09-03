#pragma once
#include <iostream>

class Utils {
public:
    std::string static const getEnvironmentVariableConnectionString();
    unsigned long static const hash_password(std::string str);
};