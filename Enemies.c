#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"




void Draw_STAR(char(*aLevel), char(*aActors), int x_position, int y_position, int level_height, int level_width)
{
	int x, y;
	float angle, a, b;


	aActors[x_position + y_position * level_width] = 'P';

		
		for (y = y_position; y > 0; y--)
		{
			a = (float)(((x) * sin(angle)) + ((y) * cos(angle)) + y_position);
			b = (float)(((x) * cos(angle)) - ((y) * sin(angle)) + x_position);

			aActors[(int)floor(b) + (int)floor(a) * level_width] = 'P';
			
		}

		for (y = y_position; y < level_height - y_position; y++)
		{
			//aActors[(-y * sin(angle)) + y * level_width] = 'P';

		}

		for (x = x_position; x > 0; x--)
		{
			aActors[x + y_position * level_width] = 'P';

		}

		for (x = x_position; x < level_width - x_position; x++)
		{
			aActors[x + y_position * level_width] = 'P';

		}
}




//x = xcos - ysin
//y = xsin + ycos