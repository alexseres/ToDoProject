#include "Button.h"

Button::Button(){
    rectangle.h = 100;
    rectangle.w = 200;
    rectangle.x = 0;
};

void Button::update(Mouse &mouse, SDL_Renderer *renderer) {
//is the mouse colliding with the button?!
    SDL_SetRenderDrawColor(renderer, 200, 0,0,24);
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderPresent(renderer);


    if(SDL_HasIntersection(&rectangle, &mouse.point)){
        isSelected = true;
        std::cout << "Has intersection" << std::endl;
    }else{
        isSelected = false;
//        std::cout << "No intersection" << std::endl;
    }
}

//void Button::draw(SDL_Renderer *renderer) {
//    SDL_RenderCopy(renderer, tex, &rectangle);
//
//}