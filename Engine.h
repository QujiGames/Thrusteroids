#pragma once


void Get_Inputs();
void RenderScene(char(*arr), int width, int height);

void Get_Inputs(float velocityX, float velocityY, float angle, unsigned short MSB);

void Draw_Screen2(int velocityX, int velocityY, int xTrans, int yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen), float Gravity);


void ClearScreen2(char(*aScreen), int screen_width, int screen_height);