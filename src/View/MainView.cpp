#include "MainView.h"

void MainView::print_user_info(){
    std::cout << "***************************************************************************************************" << std::endl;
//    for(int i = 0;i < user.get_tables().size(); i++){
//        cout <<"|   " << setw(29)  <<  left << user.get_tables()[i].get_table_name();
//        vector<Card> cards = user.get_tables()[i].get_cards();
//
//        for(int k = 0;k < user.get_tables()[i].get_cards().size();k++){
//
//            cout <<"|   " << setw(29)  <<  left << cards[k].get_description() << "\n";
//        }
//        std::cout<<'\t';
//    }


    int longest_card_vector_size = Utils::get_longest_vector_size(user.get_tables());
    std::vector<Table> tables = user.get_tables();
    for(int i = 0;i < longest_card_vector_size;i++){
        std::stringstream ss;
        for(int j = 0;j < tables[i].get_cards().size();j++){
            std::vector<Card> cards = tables[i].get_cards();
            if(tables[j].get_cards()[i] == ){
                ss << " ";
                continue;
            }
            else{
                ss <<  tables[j].get_cards()[i].get_description() + " ";
            }
        }
        ss << "\n";
        cout << ss.str() << endl;
    }
}

void MainView::operate() {
    print_user_info();
//    for(int i = 0;i < 4;i++){
//        std::stringstream ss;
//        for(int j = 0;j < arr.size();j++){
//            if(arr[j][i] == 0){
//                ss << " ";
//                continue;
//            }
//            else{
//                ss <<  to_string(arr[j][i]) + " ";
//            }
//        }
//        ss << "\n";
//        cout << ss.str() << endl;
//    }


}


//        std::cout << "   " + user.get_tables()[i].get_table_name() + "  |";
//        printf("%-4s%-21s%-3s\n", "   ", user.get_tables()[i].get_table_name().c_str(), "   |");
//        if(i == user.get_tables().size() - 1)
//        {
//            std::cout<<"|";
//            std::cout<<'\t';
//        }
//    for(int i = 0;i < arr.size();i++){
//        std::stringstream ss;
//        for(int j = 0;j < 4;j++){
//            if(arr[i].size() <= j) continue;
//            ss <<  to_string(arr[i][j]) + " ";
//        }
//        ss << "\n";
//        cout << ss.str() << endl;
//    }
