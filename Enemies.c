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

		
		for (x = x_position; x < x_position + size; x++)
		{
			a = (float)(((x-x_position)*sin(angle)) + ((y)*cos(angle)) + y_position);
			b = (float)(((x-x_position)*cos(angle)) - ((y)*sin(angle)) + x_position);


			if (a > 0 && b > 0 && b <= (level_height - 1) && a <= (level_width - 1))
			{
				aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			}
		}

		


}
void Create_Cruiser(int valid_loc, int level_width, double(*arr), int how_many)
{
	double x, y;
	double x_vel = -0.005, y_vel = 0.005;

	x = valid_loc % level_width;
	y = (valid_loc - x) / level_width;

	for (int i = 4; i < (5*how_many);i+=5)
	{
		if (arr[i] == 0)
		{
			arr[i - 4] = x;
			arr[i - 3] = y;
			arr[i - 2] = x_vel;
			arr[i - 1] = y_vel;
			arr[i] = 1;

		}
			


	}



}

void  Draw_Cruiser(char(*Arr), int x_position, int y_position, int level_width, int level_height, float velocityX, float velocityY, float time, double(*arr2), int *bullets_fired, int xloc, int yloc, int fire, int(*aCruisers))




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
	

	if (fire == 1)
	{
		for (int i = 0; i < 10000; i++)

			if (arr2[0 + i * 5] == '\0')
			{
				arr2[0 + i * 5] = (double)(x_position + 1);
				arr2[1 + i * 5] = (double)(y_position + 1);
				arr2[2 + i * 5] = (double)(x_vel);
				arr2[3 + i * 5] = (double)(y_vel);
				arr2[4 + i * 5] = 2;


				
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


void Cruiser_AI(double(*aCruisers), char(*aLevel), int shipX, int shipY, int level_width)

{
	int i, j, x, y;
	
	for (i = 4; i < 4000; i += 5)
	{
		if (aCruisers[i] == 1)
		{

			
			double xDiff = shipX - aCruisers[i-4];
			double yDiff = shipY - aCruisers[i-3];
			double x_vel = 0;
			double y_vel = 0;
			double angle = 0;

			double ship_speed = 0.005; 

			//Starts off working out ship location and aims towards it as a default action
			

			if (xDiff <= 0)
			{
				if (yDiff <= 0)
				{
					angle = atan(xDiff / yDiff);
					x_vel = -ship_speed * sin(angle) ;
					y_vel = -ship_speed * cos(angle) ;

				}
				else if (yDiff >= 0)
				{
					angle = atan(xDiff / yDiff) + 3.14;
					x_vel = -ship_speed * sin(angle) ;
					y_vel = -ship_speed * cos(angle) ;

				}
			}
			else if (xDiff >= 0)
			{
				if (yDiff <= 0)
				{
					angle = atan(xDiff / yDiff) + 3.14;
					x_vel = ship_speed * sin(angle) ;
					y_vel = ship_speed * cos(angle) ;
				}
				else if (yDiff >= 0)
				{

					angle = atan(xDiff / yDiff);
					x_vel = ship_speed * sin(angle) ;
					y_vel = ship_speed * cos(angle) ;

				}
			}
			
			aCruisers[i - 2] = x_vel;
			aCruisers[i - 1] = y_vel;
			
			
			
			
			
			
			// next check for collison, this will overwrite default velocities
			
			
			
			
			
			
			//loop to check for collison with vertical walls

			
			for (j = 1; j <10; j++) 

			{
				x = (int)aCruisers[i - 4];
				y = (int)aCruisers[i - 3] - j;
				

				if (aLevel[x+y * level_width] != '\0' && aLevel[x + y * level_width] != '.' && aLevel[x + y * level_width] != '*' && aLevel[x + y * level_width] != '+')  //test to see if there is a wall within 5 spaces above and set velocity to downwards if there is
				{
					aCruisers[i - 1] = 0.005;
					

					if (aCruisers[i - 2] == 0)
					{
					aCruisers[i - 2] = 0.005;
					}

				}
				y = (int)aCruisers[i - 3] + j;
				if (aLevel[x + y * level_width] != '\0' && aLevel[x + y * level_width] != '.' && aLevel[x + y * level_width] != '*' && aLevel[x + y * level_width] != '+') //test to see if there is a wall within 5 spaces below and set velocity to downwards if there is
				{
					aCruisers[i - 1] = -0.005;
					if (aCruisers[i - 2] == 0)
					{
						aCruisers[i - 2] = 0.005;

					}

				}
			}


			//loop toe check for collison with horizontal walls


			for (j = 1; j < 10;j++)

			{
				x = (int)aCruisers[i - 4] - j;
				y = (int)aCruisers[i - 3] ;
			

				if (aLevel[x + y * level_width] != '\0' && aLevel[x + y * level_width] != '.' && aLevel[x + y * level_width] != '*' && aLevel[x + y * level_width] != '+')  //test to see if there is a wall within 5 spaces above and set velocity to downwards if there is
				{
					aCruisers[i - 2] = 0.005;


					if (aCruisers[i - 1] == 0)
					{
						aCruisers[i - 1] = 0.005;
					}

				}
				x = aCruisers[i - 4] + j;
				if (aLevel[x + y * level_width] != '\0' && aLevel[x + y * level_width] != '.' && aLevel[x + y * level_width] != '*' && aLevel[x + y * level_width] != '+') //test to see if there is a wall within 5 spaces below and set velocity to downwards if there is
				{
					aCruisers[i - 2] = -0.005;
					if ((int)aCruisers[i - 1] == 0)
					{
						aCruisers[i - 1] = 0.005;

					}

				}
			}



		}


	}

	





}

void Destroy_Cruiser(double(*aCruisers), int x, int y)

{
	

	int i, x_diff, y_diff;
	


     	for (i = 0; i < 1000; i+=5)
	{

 		x_diff = abs(aCruisers[i] - x);
		y_diff = abs(aCruisers[i + 1] - y);

		if (x_diff <5  && y_diff <5)
		{
			aCruisers[i] = '\0';
			aCruisers[i+1] = '\0';
			aCruisers[i+2] = '\0';
			aCruisers[i+3] = '\0';
			aCruisers[i + 4] = 0;

			

					   	}



	}



}

