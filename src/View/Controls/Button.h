#ifndef TODOPROJECT_BUTTON_H
#define TODOPROJECT_BUTTON_H
#include <iostream>
#include "/usr/local/Cellar/sdl2/2.0.20/include/SDL2/SDL.h"
#include "Mouse.h"

class Button {
public:
    SDL_Texture *tex;
    SDL_Rect rectangle;
    bool isSelected = false;
    Button();

    void update(Mouse& mouse, SDL_Renderer *renderer);
//    void draw(SDL_Renderer *renderer);

};


#endif //TODOPROJECT_BUTTON_H
