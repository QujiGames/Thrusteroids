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