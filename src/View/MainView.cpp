#include "MainView.h"

void MainView::print_user_info(){

    std::cout << "****************************************************************************************************************" << std::endl;
    for(int i = 0;i < user.get_tables().size(); i++){
        std::cout <<"* " << left << setw(35) << user.get_tables()[i].get_table_name();
    }
    std::cout << "*";
    std::cout << "\n";
    std::cout << "****************************************************************************************************************" << std::endl;

    int longest_card_vector_size = Utils::get_longest_vector_size(user.get_tables());

    for(int i = 0;i < longest_card_vector_size;i++){
        std::stringstream ss;
        for(int j = 0;j < user.get_tables().size();j++){
            if(user.get_tables()[j].get_cards().size() <= i){
                ss << "                                     ";
                continue;
            }
            else{
                ss << "* " << to_string(user.get_tables()[j].get_cards()[i].get_view_id()) << ". " << left << setw(32) << user.get_tables()[j].get_cards()[i].get_description() ;
            }
        }
        std::cout << ss.str() << "*" << std::endl;
    }
}

map<int, Card> MainView::initialize_card_map(std::vector<Table> &tables){
    int counter = 1;
    for(int i = 0;i < tables.size();i++){
        for(int j = 0;j < tables[i].get_cards().size();j++){
            tables[i].get_cards()[j].set_view_id(counter);
            card_map.insert(make_pair(counter, tables[i].get_cards()[j]));
            ++counter;
        }
    }
    return card_map;
}


void MainView::operate() {
    initialize_card_map(user.get_tables());
    print_user_info();
}
