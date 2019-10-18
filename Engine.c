#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"



void Get_Inputs(int vel)

{
	if (GetAsyncKeyState(VK_UP))
	{
		vel = -vel;

	}

}


//sub routine to take an array input and draw it to the screen

void RenderScene(char(*arr), int width, int height)
{
	Console_ClearRenderBuffer();

	int i, j;

	for (i = 0; i < height; ++i)
	{
		for (j = 0; j < width; ++j)
		{
			Console_SetRenderBuffer_Char(i, j, arr[i + j * 40]);
		}
	}

	Console_SwapRenderBuffer();


}