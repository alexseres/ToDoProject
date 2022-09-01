//
// Created by Alex Seres on 01/09/2022.
//

#include "Signer.h"

void Signer::introduction() {
    bool running = true;
    while(running){
        int option;
        std::cout << "*---------------------------------*";
        std::cout << "*-----Welcome to the ToDoAPP------*";
        std::cout << "*---------------------------------*";
        std::cout << "*-Please select from the options!-*";
        std::cout << "*----------1.Registration---------*";
        std::cout << "*----------2.Sign in--------------*";
        std::cout << "*----------3.Quit-----------------*";
        std::cout << "*---------------------------------*";
        std::cin >> option;
        if(option == 1 || option == 2 || option 3){
            if(option == 1){
                registration();
            }
            else if(option == 2){
                sign_in();
            }
            else if(option == 3){
                std::cout <<"You have quit from the app" << std::endl;
                running = false;
            }
            else{
                std::cout <<"Please try again" << std::endl;
            }
        }
    }
}

void Signer::registration() {
    bool running = true;
    std::string user_name;
    std::string password;
    std::string salt;
    while(running){
        std::string user_name;
        std::cout << "*---------------------------------*";
        std::cout << "*-----------Registration----------*";
        std::cout << "*---------------------------------*";
        std::cout << "*----Please create a user name----*";
        std::cout << "*------Maximum 12 characters------*";
        std::cin >> user_name;
        if(user_name.size() > 12){
            std::cout <<"Its more than 12 character, try again" << std::endl;
            continue;
        }
        std::cout << "*----Please create a password!----*";
        std::cout << "*------Maximum 12 characters------*";
        std::cin >> password;
        if(user_name.size() > 12){
            std::cout <<"Its more than 12 character, try again" << std::endl;
            continue;
        }
        std::cout << "*------Please create a salt-------*";
        std::cout << "*------Maximum 7 characters-------*";
        std::cin >> salt;
        if(user_name.size() > 7){
            std::cout <<"Its more than 7 character, try again" << std::endl;
            continue;
        }

    }
}