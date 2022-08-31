#include <iostream>

class User {
private:
    std::string uuid;
    std::string user_name;
    std::string hashed_value;
    std::string salt;
public:
    User();
};
