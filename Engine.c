#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Console/Console.h"


// Placeholder function does nothing at the moment
void Get_Inputs(int vel)

{
	if (GetAsyncKeyState(VK_UP))
	{
		vel = -vel;

	}

}


//sub routine to take an array input and draw it to the screen.  arr is the array passed eg aScreen

void RenderScene(char(*arr), int width, int height)
{
	Console_ClearRenderBuffer();

	int i, j;

	for (i = 0; i < height; ++i)
	{
		for (j = 0; j < width; ++j)
		{
			if (arr[i + j * 40] == '|')
 			{
				// Draw laser as green
				Console_SetRenderBuffer_Char(i, j, arr[i + j * 40],0,0,0x0002);
				
			}
			else if (arr[i + j * 40] == '!')
			{
				// draw rocket tail red
				Console_SetRenderBuffer_Char(i, j, arr[i + j * 40], 0x0004, 0, 0);

			}
			else
			{

				//Draw screen elements

				Console_SetRenderBuffer_Char(i, j, arr[i + j * 40],0x0004, 0x0001, 0x0002);
			}
		}
	}

	Console_SwapRenderBuffer();


}