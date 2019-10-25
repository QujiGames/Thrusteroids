#pragma once



void RenderScene(char(*arr), int width, int height, int score, float angle, double accel, double velx, double vely);


void Draw_Screen(float xTrans, float yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen), char(*aActors), int pressed, int gunFired);

void draw_UI(score, angle, velx, vely, accel);

void ClearScreen(char(*aScreen), int screen_width, int screen_height);

int Generate_valid_location(int level_width, int level_height, char(*arr));


int Is_Location_Valid(int x, int y, int level_width, int level_height, char(*arr));
