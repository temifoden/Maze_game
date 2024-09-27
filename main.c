#include "raycasting.h"

/**
 * code description here
 */
int main(int argc, char* args[]) {
    Uint32 oldTime = 0, currentTime = 0;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    bool quit = false;
    SDL_Event e;
////    Movement variables
//    const double moveSpeed = 0.5; // Adjust the movement speed
//    const double rotSpeed = 0.05;  // Adjust the rotation speed

    while (!quit) {
        currentTime = SDL_GetTicks();
        double frameTime = (currentTime - oldTime) / 1000.0;
        oldTime = currentTime;
        //    Movement variables
            double moveSpeed = frameTime * 5.0; // Adjust the movement speed
            double rotSpeed = frameTime * 3.0;  // Adjust the rotation speed
        //  event handling
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT){
                quit = true;
            }
            
        //  handle key presses
        //   else if (e.type == SDL_KEYDOWN) {
        //      handle input from handleinput function
        //           handleInput(e.key.keysym.sym, moveSpeed, rotSpeed);
        //   }
        }
        handleContinuousInput(keystates, moveSpeed, rotSpeed);
        

        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);  // Sky blue for ceiling
        SDL_RenderClear(renderer);

        render(renderer);  // Call the render function from raycasting.c

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
