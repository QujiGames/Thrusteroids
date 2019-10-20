
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
	Random_Init();

	return Random_Range(min, max);

}



char * Level_Generator(int height, int width)
{
	// doesn't work, need to use memory allocation to assign a variable to an array size
	// const int level_size = height * width;
	char Terrain[1600];
	
	//
	//	HARD CODED VALUES!!!
	//

	
	//Outer loop is y axis || Inner loop is x axis
	for (int i = 0; i < 40; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			/*
			*	jitter is x direction
			*	variance is y direction
			*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
			*/
			int jitter = Level_Seed(1, 2);
			int variance = Level_Seed(1, 2);
			int direction = Level_Seed(-1, 1);


			if (i >= 30 && i <= 35)
			{
				Terrain[j + (i * 40)] = '@';
			}

		}


	}

	return Terrain;

}



