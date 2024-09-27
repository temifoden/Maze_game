#ifndef RAYCASTING_H
#define RAYCASTING_H

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TILE_SIZE 64

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

// Extern declarations for global variables
extern double posX, posY;
extern double dirX, dirY;
extern double planeX, planeY;
extern int map[24][24];

// Extern declarations for screen dimensions
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// Function prototype for rendering

void render(SDL_Renderer* renderer);
void handleContinuousInput(const Uint8* keystates, double moveSpeed, double rotSpeed);
void handleInput(SDL_Keycode key, double moveSpeed, double rotSpeed);


#endif
