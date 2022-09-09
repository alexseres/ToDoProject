
#ifndef TODOPROJECT_MAINVIEW_H
#define TODOPROJECT_MAINVIEW_H
#include <iostream>
#include <utility>
#include "../Model/User.h"
#include <iomanip>
#include <sstream>
#include "../Utils/Utils.h"


class MainView {
private:
    User user;

public:
    MainView(User _user): user(std::move(_user)){};
    void print_user_info();
    void operate();
};


#endif //TODOPROJECT_MAINVIEW_H
