#include <iostream>
// #include "UserManager/SignIn.h"
#include "Manager/UserHandler.h"
#include "/usr/local/Cellar/sdl2/2.0.20/include/SDL2/SDL.h"
#include "View/SignerWindow.h"



int main(int argc, char * argv []) {    
    // UserHandler ur;
    // ur.create_user();
    srand(time(NULL));
    SignerWindow signerWindow;
    if(signerWindow.init() == false){
        std::cout << "Error initialising SDL." << std::endl;

    }

    while(true){
        if(signerWindow.processEvents() == false){
            break;
        }
    }

    return 0;
}
