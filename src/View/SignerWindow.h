#ifndef TODOPROJECT_SIGNERWINDOW_H
#define TODOPROJECT_SIGNERWINDOW_H
#include "/usr/local/Cellar/sdl2/2.0.20/include/SDL2/SDL.h"

class SignerWindow {
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture ;
    Uint32 *m_buffer;

public:
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
    void clear();
};


#endif //TODOPROJECT_SIGNERWINDOW_H
