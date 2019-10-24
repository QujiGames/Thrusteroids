#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Console/Console.h"
#include "Random/Random.h"


// Initiate game
void Game_Init(int width, int height)
{
	Console_Init();
	Random_Init();

	Console_SetTitle("Fuji Sucks");

	Console_SetSquareFont();
	Console_SetWindowedMode(width, height, false);
	Console_SetCursorVisibility(0);
	Console_CreateRenderBuffer();
	Console_SetWindowPos(800, 0);

}
//Sub routine to design the level, set as a straight line for now.
void Make_Level(char(*arr), int width, int height)

{
	int i;

	for (i = 0; i < width; i++)
	{
		arr[i + (30 * width)] = '#';
	}
	arr[0 + (29 * width)] = '#';
	arr[39 + (29 * width)] = '#';
	arr[0 + (28 * width)] = '#';
	arr[39 + (30 * width)] = '#';


}

void GameShutdown()
{

	Console_CleanUp();
}