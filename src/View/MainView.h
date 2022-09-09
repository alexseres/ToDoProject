
#ifndef TODOPROJECT_MAINVIEW_H
#define TODOPROJECT_MAINVIEW_H
#include <iostream>
#include <utility>
#include "../Model/User.h"
#include <iomanip>
#include <sstream>
#include "../Utils/Utils.h"
#include <map>


class MainView {
private:
    User user;
    map<int, Card> card_map;
public:
    MainView(User _user): user(std::move(_user)){};
    void print_user_info();
    void operate();
    map<int, Card> initialize_card_map(std::vector<Table> &tables);
};


#endif //TODOPROJECT_MAINVIEW_H
