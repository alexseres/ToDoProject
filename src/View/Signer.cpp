#include "Signer.h"

void Signer::introduction() {
    bool running = true;
    while(running){
        int option;
        std::cout << "*---------------------------------*" << std::endl;
        std::cout << "*-----Welcome to the ToDoAPP------*" << std::endl;
        std::cout << "*---------------------------------*" << std::endl;
        std::cout << "*-Please select from the options!-*" << std::endl;
        std::cout << "*----------1.Registration---------*" << std::endl;
        std::cout << "*----------2.Sign in--------------*" << std::endl;
        std::cout << "*----------3.Quit-----------------*" << std::endl;
        std::cout << "*---------------------------------*" << std::endl;
        std::cin >> option;
        if(option == 1 || option == 2 || option == 3){
            if(option == 1){
                registration();
            }
            else if(option == 2){
                sign_in_asker();
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
        std::cout << "*---------------------------------*" << std::endl;
        std::cout << "*-----------Registration----------*" << std::endl;
        std::cout << "*---------------------------------*" << std::endl;
        std::cout << "*----Please create a user name----*" << std::endl;
        std::cout << "*------Maximum 12 characters------*" << std::endl;
        std::cin >> user_name;
        if(user_name.size() > 12){
            std::cout <<"Its more than 12 character, try again" << std::endl;
            continue;
        }
        std::cout << "*----Please create a password!----*" << std::endl;
        std::cout << "*------Maximum 12 characters------*" << std::endl;
        std::cin >> password;
        if(user_name.size() > 12){
            std::cout <<"Its more than 12 character, try again" << std::endl;
            continue;
        }
        std::cout << "*------Please create a salt-------*" << std::endl;
        std::cout << "*------Maximum 7 characters-------*" << std::endl;
        std::cin >> salt;
        if(user_name.size() > 7){
            std::cout <<"Its more than 7 character, try again" << std::endl;
            continue;
        }
        int success = handler.create_user(user_name, password, salt);
        if(success == 0){
            std::cout << "User has been created" << std::endl;
            sign_in(user_name, password, salt);
        }

    }
}

void Signer::sign_in_asker() {
    bool running = true;
    std::string user_name;
    std::string password;
    std::string salt;
    while(running) {
        std::string user_name;
        std::cout << "*---------------------------------*" << std::endl;
        std::cout << "*-------------Sign in-------------*" << std::endl;
        std::cout << "*Please give your user name, pass-*" << std::endl;
        std::cout << "*word and your salt---------------*" << std::endl;
        std::cin >> user_name >> password >> salt;
        if(user_name.size() < 1 || password.size() < 1 || salt.size() < 1){
            std::cout << "One of them at least empty, please try again" << std::endl;
            continue;
        }
        sign_in(user_name, password, salt);
    }
}

void Signer::sign_in(std::string username, std::string password, std::string salt) {
    try{
        User user = handler.get_user(username, password, salt);
    }
    catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}