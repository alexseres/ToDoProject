
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
    map<int, Table> table_map;
    int card_counter = 0;
    int table_counter = 0;
public:
    MainView(UserHandler _handler,User _user): user(std::move(_user)), handler(std::move(_handler)){};
    void print_user_info();
    void operate();
    map<int, Card> initialize_card_map(std::vector<Table> &tables);
    void option_manager(bool &is_accepted);
    void add_card_option(int table_view_id);
    std::string get_table_id_by_view_id(int id);
    bool check_if_card_has_not_the_same_table_id_to_move(int card_view_id, int table_view_id);
    bool move_card(int card_choice, int new_table_id);
};


#endif //TODOPROJECT_MAINVIEW_H
