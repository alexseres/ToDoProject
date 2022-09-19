#pragma once
#include <iostream>
#include "../Model/Table.h"



class Utils {
public:
    static std::string generateUUID();
    std::string static getEnvironmentVariableConnectionString();
    unsigned long static const hash_password(std::string str);
    int static get_longest_vector_size(std::vector<Table> tables);

};