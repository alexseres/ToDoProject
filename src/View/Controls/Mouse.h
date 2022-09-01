//
// Created by Alex Seres on 01/09/2022.
//

#ifndef TODOPROJECT_MOUSE_H
#define TODOPROJECT_MOUSE_H
#include "/usr/local/Cellar/sdl2/2.0.20/include/SDL2/SDL.h"

class Mouse {
public:
    SDL_Rect rect;
    SDL_Rect point;

    Mouse(){
        rect.w = 25;
        rect.h = 25;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(true);
    }
    void update(){
        //get the location of system mouse
        //update the position
        SDL_GetMouseState(&rect.x, &rect.y);
        //update the point
        point.x = rect.x;
        point.y = rect.y;
    }




};


#endif //TODOPROJECT_MOUSE_H
