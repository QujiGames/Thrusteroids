
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"
#include "Random/Random.h"


/*	
*	level_size is the length of the array for the level, size is determined by x distance multiplied by y distance
*	e.g.	10000 equates to 100 x 100 level size
*/



int Level_Seed(int min, int max)
{
	return Random_Range(min, max);
}



void Level_Generator(char(*Terrain), int height, int width)
{
	// doesn't work, need to use memory allocation to assign a variable to an array size
	// const int level_size = height * width;
	//char Terrain[409600];
	
	//
	//	HARD CODED VALUES!!!
	//

	/*
	//Outer loop is y axis || Inner loop is x axis
	for (int y = 0; y < height; ++y)
	{
		
			/*
			*	jitter is x direction
			*	variance is y direction
			*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
			*
			int jitter = Level_Seed(1, 2);
			int variance = Level_Seed(1, 2);
			int direction = Level_Seed(-1, 1);

			if (y >= 110 && y <= 130)
			{
				
				
				
				Terrain[x + (y * width)] = '#';
			}
		}
	}

	*/
	int start_position = 120;

	int jitterweight;
	int jitter = Level_Seed(1, 5);
	int variance = Level_Seed(1, 5);
	int direction = Level_Seed(-1, 1);
	int yposition = start_position + variance;

	for (int x = 0; x < width; ++x)
	{
		jitterweight = Level_Seed(1, 100);
		jitter = Level_Seed(1, 5);
		variance = Level_Seed(1, 2);
		direction = Level_Seed(-1, 1);
			
		if (x < width && yposition < width && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				Terrain[x + (yposition * width)] = '#';
			}
			else if (jitterweight > 90)
			{
				for (int i = 0; i < jitter; ++i)
				{
					Terrain[x + (yposition * width)] = '#';
					++x;
				}
			}

			if (direction > 0)
			{
				yposition = yposition + variance;
			}
			else if (direction < 0)
			{
				yposition = yposition - variance;
			}
			else
			{
				yposition = yposition;
			}
		}

	}

}



