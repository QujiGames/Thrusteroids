#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>
#include "Game.h"
#include "Engine.h"
#include "Clock/Clock.h"
#include <math.h>
#include "ProceduralGeneration.h"
#define Gravity 1.0001f;

static int bGameIsRunning = 1;
static char aLevel[3200];
static char aScreen[3200];
static double velocity = 0.0005f;
static double velocityY = -0.005f;
static double velocityX = 0;
static double PlayerY = 0.f;
static double PlayerX = 0.f;
static double acceleration = 0.001f;
const unsigned short MSB = 0x8000;
static int pressed = 0;
static float angle = 0.f;
static float xTrans = 0;
static float yTrans = 0;
static float xMod = 0;
static float yMod = 0;
static float anglerad = 0.00000f;
static int gunFired = 0;
static int level_width = 40;
static int level_height = 80;






void Get_Inputs2()
{
	
	
	if (GetAsyncKeyState(VK_UP) & MSB)
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		
		float y = 0.005f;
		velocityY = y * cos(anglerad);
		velocityX = y * sin(anglerad);
		

	
			
		pressed = 1;

	}
	
	else
	{
		if (pressed == 1)
		{

			// return the velocity to unpressed values
		
			velocityY = -0.005f;
			velocityX = 0;
			
				
			
			pressed = 0;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		//rotate 
		angle = angle + 10 * (Clock_GetDeltaTime() / 1000.f);
		if (angle > 360)
		{
			angle = angle - 360;
		}
	}


	if (GetAsyncKeyState(VK_RIGHT))
	{
		//rotate
		angle = angle - 10 * (Clock_GetDeltaTime() / 1000.f);
		if (angle < 0)
		{
			angle = angle + 360;
		}
	}

	if (GetAsyncKeyState(VK_SPACE) & MSB)
	{
		// check for psave bar pressed to fire laser
		
		gunFired = 1;
		

	}
	else 
	{
		gunFired = 0;
	}
}
void ClearScreen()
{
	// sub routine to clear the screen array.  Probably should set this to pass an array rather than hardcoded
	int i, j;

	for (i = 0; i < level_width; ++i)
	{
		for (j = 0; j < level_height; ++j)
		{
			aScreen[i + j * level_width] = '\0';
		}
	}
}

void Draw_Screen()
{
	ClearScreen();
	int x,y;
	float newY = 0.1f, newX = 0.1f;
	
	//increase velocity by gravity value, note this does nothing for directions other than down
	velocityY = velocityY * Gravity;


	//calculate translation vectors
	anglerad = ((double)angle * 3.1415 / 180.f);
	yTrans = (float)(yTrans + (velocityY) * Clock_GetDeltaTime());
	xTrans = (float)(xTrans + (velocityX) * Clock_GetDeltaTime());


	//firing the laser, call it first so the level overwrites it
	if (gunFired)

	{
		for (x = (level_height / 2 - 1); x > 0; x--)
		{

			aScreen[(level_width / 2) + x * level_width] = '|';


		}
	}

	// take the fixed aLevel array, translate and rotate it based on current positions and angles, then copy it into aScreen array ready to render.
	int xAdjust = level_width / 2;
	int yAdjust = level_height / 2;
	for (y = 0; y < level_height; ++y)
	{
		for (x = 0; x < level_width; ++x)
		{
			if (aLevel[x + y * level_width] == '#')
			{
				


				newY = (float)(((x + xTrans - xAdjust) * sin(anglerad)) + ((y + yTrans - yAdjust) * cos(anglerad)) + yAdjust);
				newX = (float)(((x + xTrans - xAdjust) * cos(anglerad)) - ((y + yTrans - yAdjust) * sin(anglerad)) + xAdjust);

				if (newY > 0 && newX > 0 && newY <= (level_height-1) && newX <= (level_width-1))
				{

					aScreen[(int)floor(newX) + (int)floor(newY) * level_width] = '#';
				}
			}

		}
	}

	//Draw the rocket

	aScreen[(xAdjust) + (yAdjust) * (level_width)] = '^';
	aScreen[(xAdjust) + (yAdjust +1) * (level_width)] = 'O';
	aScreen[(xAdjust-1) + (yAdjust +2) * (level_width)] = '/';
	aScreen[(xAdjust+1) + (yAdjust + 2) * (level_width)] = '\\';

	if (velocityY > 0)
	{
		aScreen[(xAdjust) + (yAdjust+2) * level_width] = '!';

	}



	//Dwraw the laser
	



}



int main()
{


	Game_Init(level_width, level_height);
	 
	
	
	acceleration = Gravity;

	Make_Level(aLevel, level_width, level_height);


	while (bGameIsRunning)
	{
		Clock_GameLoopStart();
		Draw_Screen();

		RenderScene(aScreen, level_width , level_height);
		Get_Inputs2();
	}
	GameShutdown();
}
