
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


		//
		//
		//  Boundary issues exist, generating level beyond boundary box, need to fix
		//
		//




		if (x <= width && yposition <= height && yposition > 0)
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
				int xcount = 0;
				Terrain[(x - 1) + (yposition * width)] = 'X';
				Terrain[x + (yposition * width)] = 'R';
				for (int i = 0; i <= jitter; i++)
				{
					Terrain[(x + i) + (yposition * width)] = 'J';
					xcount++;
				}
				x = x + xcount;
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




void Draw_Wall2(char(*Terrain), int width, int height, int starting_position)
{
	

	int jitterweight;
	int jitter = Level_Seed(1, 5);
	int variance = Level_Seed(1, 5);
	int direction = Level_Seed(-1, 1);





	for (int x = 0; x < width; x++)
	{
		jitterweight = Level_Seed(1, 100);
		jitter = Level_Seed(1, 5);
		variance = Level_Seed(1, 2);
		direction = Level_Seed(-1, 1);
		int oldyposition = starting_position;
		int	yposition = starting_position + variance;









		//
		//
		//  Boundary issues exist, generating level beyond boundary box, need to fix
		//
		//




			/*
			*	jitter is x direction
			*	variance is y direction
			*	direction is the direction the terrain is generated; -1 is -y, 0 is +x, 1 is +y
			*/
		
		if (x <= width && yposition <= height && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{


					if (direction > 0)
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
					else if (direction < 0)
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
					else
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
				}
				else if (variance > 1)
				{


					if (direction > 0)
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
					else if (direction < 0)
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
					else
					{
						for (int i = oldyposition; i < yposition + variance; i++)
						{
							Terrain[x + (yposition * width)] = 'J';
						}

						oldyposition = yposition;
					}
				}
			}
			else if (jitterweight > 90)
			{
				for (int i = oldyposition; i < yposition + variance; i++)
				{
					Terrain[x + (yposition * width)] = 'J';
				}

				oldyposition = yposition;
			}
		}

		/*
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
		*/
	}
}



void Draw_Wall3(char(*Terrain), int width, int height, int starting_position)
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


		//
		//
		//  Boundary issues exist, generating level beyond boundary box, need to fix
		//
		//




		if (x <= width && yposition <= height && yposition > 0)
		{
			if (jitterweight <= 90)
			{
				if (variance == 1)
				{
					if (direction > 0)
					{
						Terrain[x + ((yposition) * width)] = 'w';
						Terrain[x + ((yposition - 1) * width)] = 'W';
					}
					else if (direction < 0)
					{
						Terrain[x + ((yposition) * width)] = 'e';
						Terrain[x + ((yposition + 1) * width)] = 'E';
					}
					else
					{
						Terrain[x + (yposition * width)] = 'R';
						Terrain[x + 1 + (yposition * width)] = 'r';
					}
				}
				
				else if (variance > 1)
				{
					if (direction > 0)
					{
						int ycount = 0;
						for (int i = 0; i <= variance; i++)
						{
							Terrain[x + ((yposition + 1 + i) * width)] = 'T';
							ycount++;
						}
						yposition = yposition + ycount - 1;
					}
					else if (direction < 0)
					{
						int ycount = 0;
						for (int i = 0; i <= variance; i++)
						{

							Terrain[x + ((yposition - 1 - i) * width)] = 'J';
							ycount++;
						}
						yposition = yposition - ycount + 1;
					}
					else
					{
						for (int i = 0; i <= variance; i++)
						{

							Terrain[x + ((yposition)*width)] = 'X';
						}
					}
				}
				
			}
			else if (jitterweight > 90)
			{
				int xcount = 0;

				for (int i = 0; i <= jitter; i++)
				{
					Terrain[(x + i) + (yposition * width)] = 'Z';
					xcount++;
				}
				x = x + xcount - 1;
			}
		}

		if (direction > 0)
		{
			if (variance > 1)
			{
				yposition = yposition + variance - 2;
			}
			else
			{
				yposition = yposition + variance - 1;
			}
		}
		else if (direction < 0)
		{
			if (variance > 1)
			{
				yposition = yposition - variance + 2;
			}
			else
			{
				yposition = yposition - variance + 1;
			}
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
	int i;

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
						
						for(i = 4; i > 0; i--)
						{

							Terrain[x + ((yposition - i) * width)] = 'a';
						}
					}
					else if (direction < 0)
					{
						for (i = 4; i > 0; i--)
						{
							Terrain[x + ((yposition - i) * width)] = 'r';
						}
					}
					else
					{
						for (i = 4; i > 0; i--)
						{
							Terrain[(x - 1) + ((yposition - i) * width)] = 'q';
							Terrain[(x - 1) + (yposition * width)] = 'w';
						}
					}
				}
				else if (variance > 1)
				{
					Terrain[x + ((yposition) * width)] = 'E';

					if (direction > 0)
					{
						for (i = 4; i > 0; i--)
						{
							Terrain[x + ((yposition - 1) * width)] = 'B';
							for (int j = 0; j <= variance; j++)
							{
								Terrain[x + ((yposition + i) * width)] = 'B';
							}
						}
					}
					else if (direction < 0)
					{
						for (i = 4; i > 0; i--)
						{
							Terrain[x + ((yposition - i) * width)] = 'C';
							for (int j = 0; j <= variance; j++)
							{
								Terrain[x + ((yposition - i) * width)] = 'C';
							}
						}
					}
					else
					{
						for (i = 4; i > 0; i--)
						{
							Terrain[(x - 1) + ((yposition - i)*width)] = 'T';
							for (int j = 0; j <= variance; j++)
							{
								Terrain[x + ((yposition - i) * width)] = 'Z';
							}
						}
					}
				}
			}
			else if (jitterweight > 90)
			{
				for (i = 4; i > 0; i--)
				{
					Terrain[(x - 1) + ((yposition -i)* width)] = 'X';
					Terrain[x + ((yposition - i) * width)] = 'R';
					for (int j = 0; j <= jitter; j++)
					{
						x+j;
						Terrain[x + ((yposition - i) * width)] = 'J';
					}
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

void Star_Field(char(*Terrain), int width, int height)
{
	int small_star = 0;
	int big_star = 0;
	int star_bool = 0;

	for (int x = 40; x < width; x = x + 40)
	{
		for (int y = 40; y < height; y = y + 40)
		{
			star_bool = Level_Seed(0, 3);

			int star_xpos = Level_Seed(x - 25, x + 25);
			int star_ypos = Level_Seed(y - 25, y + 25);

			if (star_xpos < width && star_ypos < height)
			{
				if (star_bool == 3)
				{
					Terrain[star_xpos + (star_ypos * width)] = '+';
				}
				else
				{
					Terrain[star_xpos + (star_ypos * width)] = '.';
				}
			}
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
	//*yTrans = (float)(0 - Level_Seed(1, (height - (screen_height / 2))));



	Bounding_Box(Terrain, width, height);


	Draw_Wall3(Terrain, width, height, starting_position);
	Draw_Wall(Terrain, width, height, 120);
	Draw_Wall(Terrain, width, height, 300);
	Draw_Wall(Terrain, width, height, 500);

	Star_Field(Terrain, width, height);



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










