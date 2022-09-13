#ifndef TODOPROJECT_SIGNER_H
#define TODOPROJECT_SIGNER_H
#include <iostream>
#include "../Model/UserHandler.h"
#include "../Model/User.h"
#include "MainView.h"

class Signer {
private:
    UserHandler handler;
public:
    void introduction();
    void registration();
    void sign_in_asker();
    void sign_in(std::string username, std::string password, std::string salt, bool &runner);
};


#endif //TODOPROJECT_SIGNER_H
