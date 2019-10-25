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


void  Draw_Cruiser(char(*Arr), int x_position, int y_position, int level_width, int level_height, float velocityX, float velocityY, float time, double(*arr2), int *bullets_fired, int xloc, int yloc, int fire)

{

	/*

	we find difference between position of enemy and the player, then take this difference nad use it to determine an angle to the player

	We then use this angle to work out x and y vector components for velocity and set the bullet array with appropriate values
	*/


	double xDiff = xloc - x_position;
	double yDiff = yloc - y_position;
	double x_vel = 0;
	double y_vel = 0;
	double angle = 0;

	double bullet_speed = 0.005; //sqrt(xDiff * xDiff+ yDiff * yDiff) / 10000;


	//multiply by time to give different speed bullets

	if (xDiff <= 0)
	{
		if (yDiff <= 0)
		{
			angle = atan(xDiff / yDiff) ;
			x_vel = -bullet_speed * sin(angle) *time;
			y_vel = -bullet_speed * cos(angle) * time;
			
		}
		else if (yDiff >= 0)
		{
			angle = atan(xDiff / yDiff)  +3.14;
			x_vel = -bullet_speed * sin(angle) * time;
			y_vel = -bullet_speed * cos(angle) * time;

		}
	}
	else if (xDiff >= 0)
	{
		if (yDiff <= 0)
		{
		angle = atan(xDiff / yDiff) + 3.14;
		x_vel = bullet_speed * sin(angle) * time;
		y_vel = bullet_speed * cos(angle) * time;
		}
		else if (yDiff >= 0)
		{
			
		angle = atan(xDiff / yDiff) ;
		x_vel = bullet_speed * sin(angle) * time;
		y_vel = bullet_speed * cos(angle) * time;

		}
	}


	//Draw a 1 to indicate position of this type of ship.  The ship is then drawn on top of the 1 in draw screen function to ensure it doesnt rotate.

	Arr[x_position + y_position * level_width] = '1';
	// fill out bullet array, position 1 = x, 2 = y, 3 = x velocity, 4 = y velocity
	int a = *bullets_fired;
	if (fire == 1)
	{
		for (int i = 0; i < 10000; i++)

			if (arr2[0 + i * 4] == '\0')
			{
				arr2[0 + i * 4] = x_position + 1;
				arr2[1 + i * 4] = y_position + 1;
				arr2[2 + i * 4] = x_vel;
				arr2[3 + i * 4] = y_vel;

				*bullets_fired = a + 1;
				i = 10000;

			}
	}
}

//x = xcos - ysin
//y = xsin + ycos

void Place_Cruiser(char(*arr), int x_position, int y_position, int level_width)

{

	// sub routine t odraw cruiser enemy, will be called when draw screen function sees a '1'

	arr[x_position + y_position *level_width]  = 'C';
	arr[x_position + 1 + y_position * level_width] = 'O';
	arr[x_position + 2 + y_position * level_width] = 'O';
	arr[x_position + 3 + y_position * level_width] = 'D';
}