#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "Enemies.h"
#include "Random/Random.h"

#include "Console/Console.h"






//sub routine to take an array input and draw it to the screen.  arr is the array passed eg aScreen

void RenderScene(char(*arr), int width, int height, int score, float angle, double accel, double velx, double vely)
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
			else if (arr[x + y * width] == '.')
			{
				Console_SetRenderBuffer_Char(x, y, arr[x + y * width], 0x0001, 0x0004,0x0002);
			}
			else if (arr[x + y * width] == '+')
			{
				Console_SetRenderBuffer_Char(x, y, arr[x + y * width], 0x0004, 0x0001, 0x0002);
			}
			else if (arr[x + y * width] == '*')
			{
				Console_SetRenderBuffer_Char(x, y, arr[x + y * width], 0x0004, 0x0001, 0x0002);
			}
			else
			{
				// Draw Terrain in colour?

				

				Console_SetRenderBuffer_Char(x, y, arr[x + y * width],0x0003, 0x0001, 0x0001);
			}

		}
	}

	char scorebuffer[20];

	snprintf(scorebuffer, 20, "%d", score);
	Console_SetRenderBuffer_String(0, 40, "Score: ");
	Console_SetRenderBuffer_String(7, 40, scorebuffer);

	char anglebuffer[20];

	int vector = 360 - (int)angle;

	snprintf(anglebuffer, 4, "%d", vector);
	Console_SetRenderBuffer_String(0, 45, "Vector: ");
	Console_SetRenderBuffer_String(7, 45, anglebuffer);


	velx = velx * 1000 * -1;
	vely = vely * 1000;

	char velxbuffer[20];

	snprintf(velxbuffer, 20, "%d", (int)velx);
	Console_SetRenderBuffer_String(0, 50, "VelX: ");
	Console_SetRenderBuffer_String(7, 50, velxbuffer);

	char velybuffer[20];

	snprintf(velybuffer, 20, "%d", (int)vely);
	Console_SetRenderBuffer_String(0, 55, "VelY: ");
	Console_SetRenderBuffer_String(7, 55, velybuffer);

	
	accel = accel * 100000;
	accel = accel + 0.00000;

	char accelbuffer[20];

	snprintf(accelbuffer, 20, "%d", (int)accel);
	Console_SetRenderBuffer_String(0, 60, "Accel: ");
	Console_SetRenderBuffer_String(7, 60, accelbuffer);

	double speed = 0;
	speed = (sqrt(pow(velx, 2) + pow(vely, 2)));
	char speedbuffer[20];

	snprintf(speedbuffer, 20, "%d", (int)speed);
	Console_SetRenderBuffer_String(0, 65, "Speed: ");
	Console_SetRenderBuffer_String(7, 65, speedbuffer);


	Console_SwapRenderBuffer();


}


void ClearScreen(char(*arr), int screen_width, int screen_height)
{
	// sub routine to clear the screen array.  Probably should set this to pass an array rather than hardcoded
	int x, y;

	for (x = 0; x < screen_width; ++x)
	{
		for (y = 0; y < screen_height; ++y)
		{
			arr[x + y * screen_width] = '\0';
		}
	}
}



void Draw_Screen( float xTrans, float yTrans, float angle, int level_width, int level_height, int screen_width, int screen_height, char(*aLevel), char(*aScreen),char(*aActors), int pressed, int gunFired)
{
	ClearScreen(aScreen, screen_width, screen_height);
	
	int x, y;
	float newY = 0.1f, newX = 0.1f;

	


	float anglerad = (angle * 3.1415 / 180.f);
	

	//firing the laser, call it first so the level overwrites it
	if (gunFired)

	{
		for (x = screen_height/2; x > screen_height/2-30; x--)
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


	//Draw the actors onto the screen, probably want to move this to draw first so level overwrites it also
	
	for (y = 0; y < level_height; ++y)
	{
		for (x = 0; x < level_width; ++x)
		{
			if (aActors[x + y * level_width] != '\0')
			{



				newY = (float)(((x + xTrans - xAdjust) * sin(anglerad)) + ((y + yTrans - yAdjust) * cos(anglerad)) + yAdjust);
				newX = (float)(((x + xTrans - xAdjust) * cos(anglerad)) - ((y + yTrans - yAdjust) * sin(anglerad)) + xAdjust);

				if (newY > 0 && newX > 0 && newY <= (screen_height - 1) && newX <= (screen_width - 1))
				{
					if (aActors[x + y * level_width] == '1')

					{
						Place_Cruiser(aScreen, newX, newY, screen_width);
					}
					else
					{
						aScreen[(int)floor(newX) + (int)floor(newY) * screen_width] = aActors[x + y * level_width];
					}
				}
			}

		}
		

		
	}

	

	 //collision_detection();

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

int Generate_valid_location(int level_width, int level_height, char(*arr))

{
	int i, x, y,top = 0,bottom = 0;
	int top_done = 0;
	Random_Init();
	x =Random_Range(0, level_width);





	for (i = 1; i < level_height; i++)

	{
		if (arr[x + i * level_width] == '#')
		{
			Generate_valid_location(level_width, level_height, arr);
		}
		else if (arr[x + i * level_height] != '\0')
		{


			top = i;
			i = level_height + 1;
		}
	}


	for (i = level_height - 2; i > top; i--)

	{
		if (arr[x + i * level_width] == '#')
		{
			Generate_valid_location(level_width, level_height, arr);
		}
		else if (arr[x + i * level_height] != '\0')
		{


			bottom = i;
			i = top - 1;
		}
	}
	y = Random_Range(top, bottom);

	return (x + y * level_width);

}

int Is_Location_Valid(int x, int y, int level_width, int level_height, char(*arr))

{
	int i, top = 0, bottom = 0;
	int top_done = 0;

	for (i = 1; i < level_height; i++)

	{
		if (arr[x + i * level_width] == '#')
		{
			return 0;
		}
		else if (arr[x + i * level_height] != '\0')
		{


			top = i;
			i = level_height + 1;
		}
	}


	for (i = level_height-2; i >top; i--)

	{
		if (arr[x + i * level_width] == '#')
		{
			return 0;
		}
		else if (arr[x + i * level_height] != '\0')
		{


			bottom = i;
			i = top -1;
		}
	}


	if(y > top && y < bottom)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}