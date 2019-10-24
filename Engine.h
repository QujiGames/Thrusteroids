#pragma once


void Get_Inputs();
void RenderScene(char(*arr), int width, int height, int score, float angle, double accel, double velx, double vely);

void Get_Inputs(float velocityX, float velocityY, float angle, unsigned short MSB);

void Draw_Screen(float xTrans, float yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen), char(*aActors), int pressed, int gunFired);


void ClearScreen(char(*aScreen), int screen_width, int screen_height);