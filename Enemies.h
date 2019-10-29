#pragma once



//draw rotating laser pattern

void Draw_STAR(char(*aLevel), char(*aActors), int x_position, int y_position, int level_height, int level_width, float time, float angle, int size, int speed);


//Draw Cruiser


void  Draw_Cruiser(char(*Arr), int x_position, int y_position, int level_width, int level_height, float velocityX, float velocityY, float time, double(*arr2), int* bullets_fired, int xloc, int yloc, int fire, int(*aCruisers));




void Place_Cruiser(char(*arr), int x_position, int y_position, int screen_width);

void Create_Cruiser(int valid_loc, int level_width, int(*arr), int how_many);

void Cruiser_AI(double(*aCruisers), char(*aLevel), int shipX, int shipY, int screen_width);
void Destroy_Cruiser(double(*aCruisers), int x, int y);
