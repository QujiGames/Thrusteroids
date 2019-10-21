
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
			/*
			*	jitter is x direction
			*	variance is y direction
			*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
			*/

	int start_position = 120;

	int jitterweight;
	int jitter = Level_Seed(1, 5);
	int variance = Level_Seed(1, 5);
	int direction = Level_Seed(-1, 1);
	int yposition = start_position + variance;

	for (int x = 0; x < width; x++)
	{
		jitterweight = Level_Seed(1, 100);
		jitter = Level_Seed(1, 5);
		variance = Level_Seed(1, 2);
		direction = Level_Seed(-1, 1);
			
		if (x < width && yposition < width && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{
					Terrain[x + (yposition * width)] = '#';
				}
				else if (variance > 1)
				{
					for (int i = 0; i < variance; i++)
					{
						Terrain[x + ((yposition + i) * width)] = '@';

					}
				}
			}
			else if (jitterweight > 90)
			{
				for (int i = 0; i < jitter; i++)
				{
					Terrain[x + (yposition * width)] = 'X';
					x++;
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
				++yposition;
			}
		}
	}

}



