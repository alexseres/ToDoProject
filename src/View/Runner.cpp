#include "Runner.h"
#include "SignerWindow.h"

void Runner::run() {
    SignerWindow signerWindow;

    if(!signerWindow.init()){
        std::cout << "Error initialising SDL." << std::endl;
    }

    bool running = true;
    Mouse mouse;
    Button startButton;
    startButton.rectangle.x = 200;
    startButton.rectangle.y = 200;
//    SDL_SetRenderDrawColor(m_renderer, 100, 0,0,134);
//    SDL_RenderFillRect(m_renderer, &rect);
//    SDL_RenderPresent(m_renderer);

    while(running){
        mouse.update();
        startButton.update(mouse, signerWindow.m_renderer);
        if(!signerWindow.processEvents()){
            running = false;
        }
    }
    signerWindow.close();

}