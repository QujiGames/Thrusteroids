#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>
#include "Game.h"
#include "Engine.h"
#include "Clock/Clock.h"
#include <math.h>
#define Gravity 1.0001f;

static int bGameIsRunning = 1;
static char aLevel[1600];
static char aScreen[1600];
static double velocity = 0.0005f;
static double velocityY = -0.005f;
static double velocityX = 0.0f;
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






void Get_Inputs2()
{
	
	if (GetAsyncKeyState(VK_UP) & MSB)
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		velocityY = 0.005f ;
		velocityX = -0.005f;
			
		pressed = 1;

	}
	
	else
	{
		if (pressed == 1)
		{

			// return the velocity to unpressed values
			velocityY = -0.005f  ;
			velocityX = 0;
			pressed = 0;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		//rotate 
		angle = angle + 10 * (Clock_GetDeltaTime() / 1000.f);
		if (angle > 360)
		{
			angle = angle - 360;
		}
	}


	if (GetAsyncKeyState(VK_LEFT))
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

	for (i = 0; i < 40; ++i)
	{
		for (j = 0; j < 40; ++j)
		{
			aScreen[i + j * 40] = '\0';
		}
	}
}

void Draw_Screen()
{
	ClearScreen();
	int i, j;
	float newY = 0.1f, newX = 0.1f;
	
	//increase velocity by gravity value, note this does nothing for directions other than down
	velocityY = velocityY * Gravity;


	//calculate translation vectors
	anglerad = ((double)angle * 3.1415 / 180.f);
	yTrans = (float)(yTrans + (velocityY)*cos(anglerad) * Clock_GetDeltaTime());
	xTrans = (float)(xTrans + (velocityX)*sin(anglerad) * Clock_GetDeltaTime());



	// take the fixed aLevel array, translate and rotate it based on current positions and angles, then copy it into aScreen array ready to render.
	
	for (i = 0; i < 40; ++i)
	{
		for (j = 0; j < 40; ++j)
		{
			if (aLevel[j + i * 40] == '#')
			{


				newY = (float)(((i + yTrans - 20) * cos(anglerad)) - ((j + xTrans - 20) * sin(anglerad)) + 20);
				newX = (float)(((i + yTrans - 20) * sin(anglerad)) + ((j + xTrans - 20) * cos(anglerad)) + 20);

				if (newY > 0 && newX > 0 && newY <= 39 && newX <= 39)
				{

					aScreen[(int)floor(newX) + (int)floor(newY) * 40] = '#';
				}
			}

		}
	}

	//Draw the rocket

	aScreen[(20) + (20) * (40)] = '^';
	aScreen[(20) + (21) * (40)] = 'O';
	aScreen[(19) + (22) * (40)] = '/';
	aScreen[(21) + (22) * (40)] = '\\';

	if (velocityY > 0)
	{
		aScreen[(20) + (22) * 40] = '!';

	}



	//Draw the laser
	if (gunFired)

	{
		for (i = 19; i > 0; i--)
		{

			aScreen[20 + i * 40] = '|';


		}
	}



}



int main()
{


	Game_Init();
	
	acceleration = Gravity;

	Make_Level(aLevel, 40, 40);


	while (bGameIsRunning)
	{
		Clock_GameLoopStart();
		Draw_Screen();

		RenderScene(aScreen, 40, 40);
		Get_Inputs2();



	}
	GameShutdown();
}
