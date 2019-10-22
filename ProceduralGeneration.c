
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



void Bounding_Box(char(*Terrain), int width, int height)
{
	for (int x = 0; x < width; x++)
	{
		Terrain[x] = '#';
		Terrain[x + (width * (height - 1))] = '#';
	}

	for (int y = 0; y < height; y++)
	{
		Terrain[(width - 1) + (y * width)] = '#';
		Terrain[y * width] = '#';
	}
}


void Draw_Wall(char(*Terrain), int width, int height, int starting_position)
{
	int start_position = starting_position;

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

		int oldyposition = yposition;


		if (x < width && yposition < height && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{
					Terrain[x + (yposition * width)] = 'A';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'a';
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'r';
					}
					else
					{
						Terrain[(x - 1) + ((yposition - 1) * width)] = 'q';
						Terrain[(x - 1) + (yposition * width)] = 'w';
					}
				}
				else if (variance > 1)
				{
					Terrain[x + ((yposition)*width)] = 'E';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'B';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'B';
						}
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'C';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition - i) * width)] = 'C';
						}
					}
					else
					{
						Terrain[(x - 1) + ((yposition)*width)] = 'T';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'Z';
						}
					}
				}
			}
			else if (jitterweight > 90)
			{
				Terrain[(x - 1) + (yposition * width)] = 'X';
				Terrain[x + (yposition * width)] = 'R';
				for (int i = 0; i <= jitter; i++)
				{
					x++;
					Terrain[x + (yposition * width)] = 'J';

				}
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
			yposition++;
		}

	}
}











void Level_Generator(char(*Terrain), int width, int height, int starting_position)
{
			/*
			*	jitter is x direction
			*	variance is y direction
			*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
			*/


	Bounding_Box(Terrain, width, height);

	
	int start_position = starting_position;

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
			
		int oldyposition = yposition;


		if (x < width && yposition < height && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{
					Terrain[x + (yposition * width)] = 'A';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'a';
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'r';
					}
					else
					{
						Terrain[(x - 1) + ((yposition - 1) * width)] = 'q';
						Terrain[(x - 1) + (yposition * width)] = 'w';
					}
				}
				else if (variance > 1)
				{
					Terrain[x + ((yposition)* width)] = 'E';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'B';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'B';
						}
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'C';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition - i) * width)] = 'C';
						}
					}
					else
					{
						Terrain[(x - 1) + ((yposition) * width)] = 'T';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'Z';
						}
					}
				}
			}
			else if (jitterweight > 90)
			{
				Terrain[(x - 1) + (yposition * width)] = 'X';
				Terrain[x + (yposition * width)] = 'R';
				for (int i = 0; i <= jitter; i++)
				{
					x++;
					Terrain[x + (yposition * width)] = 'J';
					
				}
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
			yposition++;
		}

	}
}


// Testing pointers and changing the starting position etc


void Level_Generator2(char(*Terrain), int width, int height, int screen_width, int screen_height, float *xTrans, float *yTrans, int starting_position)
{
	/*
	*	jitter is x direction
	*	variance is y direction
	*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
	*/

	// xTrans, yTrans must be negative values within the bounds of the level
	//
	//	numbers not correct, must account for camera view offset (screen size / 2)
	//

	//*xTrans = (float)(0 - Level_Seed(1, (width - (screen_width / 2))));
	// *yTrans = (float)(0 - Level_Seed(1, (height - (screen_height / 2))));



	Bounding_Box(Terrain, width, height);


	Draw_Wall(Terrain, width, height, starting_position);
	Draw_Wall(Terrain, width, height, 120);
	Draw_Wall(Terrain, width, height, 300);
	Draw_Wall(Terrain, width, height, 500);



	/*

	int start_position = starting_position;

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

		int oldyposition = yposition;


		if (x < width && yposition < height && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{
					Terrain[x + (yposition * width)] = 'A';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'a';
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'r';
					}
					else
					{
						Terrain[(x - 1) + ((yposition - 1) * width)] = 'q';
						Terrain[(x - 1) + (yposition * width)] = 'w';
					}
				}
				else if (variance > 1)
				{
					Terrain[x + ((yposition)*width)] = 'E';

					if (direction > 0)
					{
						Terrain[x + ((yposition - 1) * width)] = 'B';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'B';
						}
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition + 1) * width)] = 'C';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition - i) * width)] = 'C';
						}
					}
					else
					{
						Terrain[(x - 1) + ((yposition)*width)] = 'T';
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + i) * width)] = 'Z';
						}
					}
				}
			}
			else if (jitterweight > 90)
			{
				Terrain[(x - 1) + (yposition * width)] = 'X';
				Terrain[x + (yposition * width)] = 'R';
				for (int i = 0; i <= jitter; i++)
				{
					x++;
					Terrain[x + (yposition * width)] = 'J';

				}
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
			yposition++;
		}
	}


	*/
}










