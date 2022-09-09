
#ifndef TODOPROJECT_MAINVIEW_H
#define TODOPROJECT_MAINVIEW_H
#include <iostream>
#include <utility>
#include "../Model/User.h"
#include "../Model/UserHandler.h"
#include <iomanip>
#include <sstream>
#include "../Utils/Utils.h"
#include <map>


class MainView {
private:
    User user;
    UserHandler handler;
    map<int, Card> card_map;
public:
    MainView(UserHandler _handler,User _user): user(std::move(_user)), handler(std::move(_handler)){};
    void print_user_info();
    void operate();
    map<int, Card> initialize_card_map(std::vector<Table> &tables);
    void option_manager(bool &is_accepted);
    void add_card_option(int table_view_id);
    std::string get_table_id_by_view_id(int id);
};


#endif //TODOPROJECT_MAINVIEW_H
