#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"



int pressed, gunFired;

// Placeholder function does nothing at the moment
void Get_Inputs(float velocityX, float velocityY, float angle, unsigned short MSB)

{
	
	float anglerad = ((double)angle * 3.1415 / 180.f);
	

		if (GetAsyncKeyState(VK_UP) & MSB)
		{
			// When up key is held swap the velocity, pressed variable is to allow the next part to work on release

			float y = 0.005f;
			velocityY = y * cos(anglerad);
			velocityX = y * sin(anglerad);




			pressed = 1;

		}

		else
		{
			if (pressed == 1)
			{

				// return the velocity to unpressed values

				velocityY = -0.005f;
				velocityX = 0;



				pressed = 0;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			//rotate 
			angle = angle + 10 * (Clock_GetDeltaTime() / 1000.f);
			if (angle > 360)
			{
				angle = angle - 360;
			}
		}


		if (GetAsyncKeyState(VK_RIGHT))
		{
			//rotate
			angle = angle - 10 * (Clock_GetDeltaTime() / 1000.f);
			if (angle < 0)
			{
				angle = angle + 360;
			}
		}

		if (GetAsyncKeyState(VK_SPACE) & MSB)
		{
			// check for psave bar pressed to fire laser

			gunFired = 1;


		}
		else
		{
			gunFired = 0;
		}
	

}


//sub routine to take an array input and draw it to the screen.  arr is the array passed eg aScreen

void RenderScene(char(*arr), int width, int height)
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
			else
			{

				//Draw screen elements

				Console_SetRenderBuffer_Char(x, y, arr[x + y * width],0x0004, 0x0001, 0x0002);
			}
		}
	}

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



void Draw_Screen2(int velocityX, int velocityY, int xTrans, int yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen), float Gravity)
{
	ClearScreen();
	int x, y;
	float newY = 0.1f, newX = 0.1f;

	//increase velocity by gravity value, note this does nothing for directions other than down
	


	//calculate translation vectors
	float anglerad = ((double)angle * 3.1415 / 180.f);
	


	//firing the laser, call it first so the level overwrites it
	if (gunFired)

	{
		for (x = (screen_height / 2 - 1); x > 0; x--)
		{

			aScreen[(screen_width / 2) + x * screen_width] = '|';


		}
	}

	// take the fixed aLevel array, translate and rotate it based on current positions and angles, then copy it into aScreen array ready to render.
	int xAdjust = level_width / 2;
	int yAdjust = level_height / 2;
	for (y = 0; y < level_height; ++y)
	{
		for (x = 0; x < level_width; ++x)
		{
			if (aLevel[x + y * level_width] == '#')
			{



				newY = (float)(((x + xTrans - xAdjust) * sin(anglerad)) + ((y + yTrans - yAdjust) * cos(anglerad)) + yAdjust);
				newX = (float)(((x + xTrans - xAdjust) * cos(anglerad)) - ((y + yTrans - yAdjust) * sin(anglerad)) + xAdjust);

				if (newY > 0 && newX > 0 && newY <= (screen_height - 1) && newX <= (screen_width - 1))
				{

					aScreen[(int)floor(newX) + (int)floor(newY) * screen_width] = '#';
				}
			}

		}
	}

	//Draw the rocket

	aScreen[(screen_width / 2) + (screen_height / 2) * (screen_width)] = '^';
	aScreen[(screen_width / 2) + (screen_height / 2 + 1) * (screen_width)] = 'O';
	aScreen[(screen_width / 2 - 1) + (screen_height / 2 + 2) * (screen_width)] = '/';
	aScreen[(screen_width / 2 + 1) + (screen_height / 2 + 2) * (screen_width)] = '\\';

	if (pressed > 0)
	{
		aScreen[(screen_width / 2) + (screen_height / 2 + 2) * screen_width] = '!';

	}



	//Dwraw the laser




}