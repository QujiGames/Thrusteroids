#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"






//sub routine to take an array input and draw it to the screen.  arr is the array passed eg aScreen

void RenderScene(char(*arr), int width, int height, int score)
{
	Console_ClearRenderBuffer();

	int x, y;

	for (y = 0; y < height; ++y)
	{
		for (x = 0; x < width; ++x)
		{
			if (arr[x + y * width] == '|')
 			{
				// Draw laser as green
				Console_SetRenderBuffer_Char(x, y, arr[x + y * width],0,0,0x0002);
				
			}
			else if (arr[x + y * width] == '!')
			{
				// draw rocket tail red
				Console_SetRenderBuffer_Char(x, y, arr[x + y * width], 0x0004, 0, 0);

			}

			//
			//	BELOW IS REALLY BAD, make an enum? or switch?
			//	Some other way of specifying colour for various characters?
			//	

			else if (arr[x + y * width] == '#' || arr[x + y * width] == '/' || arr[x + y * width] == '\\' || arr[x + y * width] == '>' || arr[x + y * width] == '<' || arr[x + y * width] == 'O' || arr[x + y * width] == '-' || arr[x + y * width] == '^')
			{
				//Draw bounding box in white

				Console_SetRenderBuffer_Char(x, y, arr[x + y * width], 0x0004, 0x0001, 0x0002);
			}
			else
			{
				// Draw Terrain in colour?

				

				Console_SetRenderBuffer_Char(x, y, arr[x + y * width],0x0003, 0x0001, 0x0001);
			}

		}
	}


	
	char stringbuffer[20];

	snprintf(stringbuffer, 20, "%d", score);
	Console_SetRenderBuffer_String(0, 40, "Score: ");
	Console_SetRenderBuffer_String(7, 40, stringbuffer);
	


	Console_SwapRenderBuffer();


}

void ClearScreen2(char(*aScreen), int screen_width, int screen_height)
{
	// sub routine to clear the screen array.  Probably should set this to pass an array rather than hardcoded
	int x, y;

	for (x = 0; x < screen_width; ++x)
	{
		for (y = 0; y < screen_height; ++y)
		{
			aScreen[x + y * screen_width] = '\0';
		}
	}
}



void Draw_Screen2( float xTrans, float yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen), int pressed, int gunFired)
{
	ClearScreen();
	int x, y;
	float newY = 0.1f, newX = 0.1f;

	


	float anglerad = (angle * 3.1415 / 180.f);
	

	//firing the laser, call it first so the level overwrites it
	if (gunFired)

	{
		for (x = (screen_height / 2 - 1); x > 0; x--)
		{

			aScreen[(screen_width / 2) + x * screen_width] = '|';


		}
	}

	// take the fixed aLevel array, translate and rotate it based on current positions and angles, then copy it into aScreen array ready to render.
	int xAdjust = screen_width / 2;
	int yAdjust = screen_height / 2;
	for (y = 0; y < level_height; ++y)
	{
		for (x = 0; x < level_width; ++x)
		{
			if (aLevel[x + y * level_width] != '\0')
			{



				newY = (float)(((x + xTrans - xAdjust) * sin(anglerad)) + ((y + yTrans - yAdjust) * cos(anglerad)) + yAdjust);
				newX = (float)(((x + xTrans - xAdjust) * cos(anglerad)) - ((y + yTrans - yAdjust) * sin(anglerad)) + xAdjust);

				if (newY > 0 && newX > 0 && newY <= (screen_height - 1) && newX <= (screen_width - 1))
				{

					aScreen[(int)floor(newX) + (int)floor(newY) * screen_width] = aLevel[x + y * level_width];
				}
			}

		}
	}
	 collision_detection();

	//Draw the rocket

	aScreen[(screen_width / 2) + (screen_height / 2) * (screen_width)] = '^';
	aScreen[(screen_width / 2 - 1) + (screen_height / 2 + 1) * (screen_width)] = '<';
	aScreen[(screen_width / 2 - 2) + (screen_height / 2 + 1) * (screen_width)] = '-';
	aScreen[(screen_width / 2) + (screen_height / 2 + 1) * (screen_width)] = 'O';
	aScreen[(screen_width / 2 + 1) + (screen_height / 2 + 1) * (screen_width)] = '>';
	aScreen[(screen_width / 2 + 2) + (screen_height / 2 + 1) * (screen_width)] = '-';
	aScreen[(screen_width / 2 - 1) + (screen_height / 2 + 2) * (screen_width)] = '/';
	aScreen[(screen_width / 2 + 1) + (screen_height / 2 + 2) * (screen_width)] = '\\';


	//Only draw the flame when we accelerate
	if (pressed > 0)
	{
		aScreen[(screen_width / 2) + (screen_height / 2 + 2) * screen_width] = '!';

	}



	//Dwraw the laser




}

