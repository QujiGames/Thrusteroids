#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "Engine.h"

#include "Console/Console.h"




void Draw_STAR(char(*aLevel), char(*aActors), int x_position, int y_position, int level_height, int level_width, float time, float angle, int size, int speed)
{
	int x =0, y=0;
	float  a, b;

	angle = angle + (speed * time / 1000);


	angle = (angle * 3.1415 / 180);
	//ClearScreen2(aActors, level_width, level_height);

	aActors[x_position + y_position * level_width] = 'P';

		//-200 is fix to make laser big enough for the moment.  Need to add collision detection
		
	//upwards
	for (y = y_position; y > y_position-size; y--)
		{
			a = (float)(((x) * sin(angle)) + ((y-y_position) * cos(angle)) + y_position);
			b = (float)(((x) * cos(angle)) - ((y- y_position) * sin(angle)) + x_position);


			if (a > 0 && b > 0 && b <= (level_height - 1) && a <= (level_width - 1))
			{
				aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			}
		}
		x = 0;
		y = 0;
		

		//downwards
		for (y = y_position; y < y_position+size; y++)
		{
			a = (float)(((x)*sin(angle)) + ((y-y_position)*cos(angle)) + y_position);
			b = (float)(((x)*cos(angle)) - ((y-y_position)*sin(angle)) + x_position);

			if (a > 0 && b > 0 && b <= (level_height - 1) && a <= (level_width - 1))
			{
				aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			}

		}
		x= 0;
		y = 0;
		


		//left
		for (x = x_position; x > x_position-size; x--)
		{
			a = (float)(((x-x_position)*sin(angle)) + ((y)*cos(angle)) + y_position);
			b = (float)(((x-x_position)*cos(angle)) - ((y)*sin(angle)) + x_position);


			if (a > 0 && b > 0 && b <= (level_height - 1) && a <= (level_width - 1))
			{
				aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			}

		}
		x = 0;
		y = 0;
		

		//right

		
		for (x = x_position; x < x_position+size; x++)
		{
			a = (float)(((x-x_position)*sin(angle)) + ((y)*cos(angle)) + y_position);
			b = (float)(((x-x_position)*cos(angle)) - ((y)*sin(angle)) + x_position);


			if (a > 0 && b > 0 && b <= (level_height - 1) && a <= (level_width - 1))
			{
				aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			}
		}

		


}


void Draw_Cruiser(char(*Arr), int x_position, int y_position, int level_width, int level_height, float velocityX, float velocityY, float time)

{

	Arr[x_position + y_position * level_width] = 'C';
	Arr[x_position+ 1 + y_position * level_width] = 'O';
	Arr[x_position + 2 + y_position * level_width] = 'O';
	Arr[x_position + 3 + y_position * level_width] = 'D';



}

//x = xcos - ysin
//y = xsin + ycos