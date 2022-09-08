//
// Created by Alex Seres on 05/09/2022.
//

#ifndef TODOPROJECT_MAINVIEW_H
#define TODOPROJECT_MAINVIEW_H
#include <iostream>
#include "../Model/User.h"


class MainView {
private:
    User user;
public:
    MainView(const User& _user): user(_user){};
    void operate();
};


#endif //TODOPROJECT_MAINVIEW_H
