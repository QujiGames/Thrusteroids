#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Console/Console.h"
#include "Random/Random.h"



void Game_Init()
{
	Console_Init();
	Random_Init();

	Console_SetTitle("Fuji Sucks");

	Console_SetSquareFont();
	Console_SetWindowedMode(40, 40, false);


}
//Sub routine to design the level, set as a straight line for now.
void Make_Level(char(*arr), int width, int height)

{
	int i;

	for (i = 0; i < width; i++)
	{
		arr[i + (30 * width)] = '#';
	}
}