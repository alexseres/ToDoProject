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
                running = false
            }
            else{
                std::cout <<"Please try again" << std::endl;
            }
        }
    }
}