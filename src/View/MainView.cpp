#include "MainView.h"



void MainView::print_user_info(){
    std::cout << "****************************************************************************************************************" << std::endl;
    std::cout << "* Options:" << std::endl;
    std::cout << "* '1' = Add card, '2' Modify card, '3' Delete Card, '4' Quit from account" << std::endl;
    std::cout << "* " << std::endl;
    std::cout << "****************************************************************************************************************" << std::endl;
    for(int i = 0;i < user.get_tables().size(); i++){
        std::cout <<"* " <<  to_string(user.get_tables()[i].get_view_id()) << ". " << left << setw(35) << user.get_tables()[i].get_table_name();
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


void MainView::operate() {
    bool is_accepted = true;
    while(is_accepted){
        user = handler.get_user(user.get_name(), user.get_password(), user.get_salt());
        initialize_card_map(user.get_tables());
        print_user_info();
        option_manager(is_accepted);
    }

}


void MainView::option_manager(bool &is_accepted) {
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 4:
            is_accepted = false;
            break;
        case 1:
            std::cout << "* Which table you want to progogate? Choose id! *" << std::endl;
            int table_choice;
            cin >> table_choice;
            if (choice < 1 || choice > user.get_tables().size()) {
                std::cout << "* There is no such an id, try again! *" << std::endl;
                break;
            }
            else{
                add_card_option(table_choice);
                break;
            }
    }
}


void MainView::add_card_option(int table_view_id) {
    std::cout << "* Give a name for the card! At least 2, maximum 13 character can it be" << std::endl;
    std::string card_name;
    cin >> card_name;
    if(card_name.empty() || card_name.size() > 13){
        std::cout << "* Requirement not been reached. Try Again!" << std::endl;
        return;
    }
    std::string table_id = get_table_id_by_view_id(table_view_id);
    handler.add_card_for_table(table_id, card_name);
}



map<int, Card> MainView::initialize_card_map(std::vector<Table> &tables){
    int table_counter = 1;
    int card_counter = 1;
    for(int i = 0;i < tables.size();i++){
        tables[i].set_view_id(table_counter);
        for(int j = 0;j < tables[i].get_cards().size();j++){
            tables[i].get_cards()[j].set_view_id(card_counter);
            card_map.insert(make_pair(card_counter, tables[i].get_cards()[j]));
            ++card_counter;
        }
        ++table_counter;
    }
    return card_map;
}

std::string MainView::get_table_id_by_view_id(int id) {
    for(Table table: user.get_tables()){
        if(id == table.get_view_id()){
            return table.get_table_id();
        }
    }
    return "Not found";
}