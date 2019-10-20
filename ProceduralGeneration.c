
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



int Level_Size(int height, int width)
{
	return height * width;
}




char * Level_Generator(static int size)
{
	
	const int level_size = size;
	char Terrain[];
	
	for (int i = 0; i < level_size; ++i)
	{

		int jitter = Level_Seed(1, 2);
		int variance = Level_Seed(1, 2);
		int direction = Level_Seed(-1, 1);



	}

}



