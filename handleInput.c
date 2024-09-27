//
//  handleInput.c
//  maze_game
//
//  Created by Temitayo on 9/22/24.
//
#include "raycasting.h"
#include <stdio.h>

// Function to handle player input
void handleInput(SDL_Keycode key, double moveSpeed, double rotSpeed)
{
    if (key == SDLK_w){
//        move forward if no wall in front
        double newPosX = posX + dirX * moveSpeed;
        double newPosY = posY + dirY * moveSpeed;
        if (map[(int)newPosX][(int)posY] == 0)
            posX = newPosX;
        if (map[(int)posX][(int)newPosY] == 0)
            posY = newPosY;
    }
    if (key == SDLK_s) {
//        move backward if no wall behind
        double newPosX = posX - dirX * moveSpeed;
        double newPosY = posY - dirY * moveSpeed;
        if (map[(int)newPosX][(int)posY] == 0)
            posX = newPosX;
        if (map[(int)posX][(int)newPosY] == 0)
            posY = newPosY;
    }
    if (key == SDLK_a) {
//        rotate to the left
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
    if (key == SDLK_d) {
//        rotate to the right
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
}
