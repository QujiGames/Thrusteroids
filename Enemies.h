#pragma once



//draw rotating laser pattern

void Draw_STAR(char(*aLevel), char(*aActors), int x_position, int y_position, int level_height, int level_width, float time, float angle, int size, int speed);


//Draw Cruiser


void  Draw_Cruiser(char(*Arr), int x_position, int y_position, int level_width, int level_height, float velocityX, float velocityY, float time, double(*arr2), int* bullets_fired, int xloc, int yloc, int fire);




void Place_Cruiser(char(*arr), int x_position, int y_position, int screen_width);