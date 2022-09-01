#include "SignerWindow.h"

bool SignerWindow::init(){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }
    m_window = SDL_CreateWindow("ToDo App",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);

    if(m_window == NULL){
        SDL_Quit();
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer,
                                  SDL_PIXELFORMAT_RGBA8888,
                                  SDL_TEXTUREACCESS_STATIC,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT);
    if(m_renderer == NULL){
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if(m_texture == NULL){
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32)); //get maxvalue

    m_buffer[30000] = 0xFFFFFFFF;
//    for(int i=0;i<SCREEN_WIDTH * SCREEN_HEIGHT;i++){
//        m_buffer[i] = 0x00FF00FF;
//    }
    return true;

}

bool SignerWindow::processEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return false;
        }
    }
    return true;
}