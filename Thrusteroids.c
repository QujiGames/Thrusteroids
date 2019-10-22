#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>
#include "Game.h"
#include "Engine.h"
#include "Clock/Clock.h"
#include <math.h>
#include "ProceduralGeneration.h"


static int bGameIsRunning = 1;
static char aLevel[1000000];
static char aScreen[25600];
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
static int level_width = 1000;
static int level_height = 1000;
static int screen_width = 160;
static int screen_height = 160;
const float Gravity = -0.0f;





void Get_Inputs2()
{
	
	
	if (GetAsyncKeyState(VK_UP) && MSB)
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		
		float y = 0.02f;
		//velocityY = y * cos(anglerad) -0.005f;
		//velocityX = y * sin(anglerad);
		
		
		acceleration = (0.015f +Gravity)* Clock_GetDeltaTime() / 1000.f;

		velocityY = velocityY + (acceleration * cos(anglerad)) ;
		velocityX = velocityX + (acceleration * sin(anglerad));
	
			
		pressed = 1;
		
	}
	
	else
	{
		acceleration = Gravity * Clock_GetDeltaTime() / 1000.f;
		velocityY = velocityY + (acceleration * cos(anglerad));
		
		if (velocityX >0)
		{
			velocityX = velocityX +  4*(acceleration);

		}
		else if (velocityX < 0)
		{
			velocityX = velocityX -  4 *(acceleration);
		}
		
		

		pressed = 0;

		/*
		if (pressed)
			// return the velocity to unpressed values
		{
			velocityY = -0.005f;
			velocityX = 0;



			pressed = 0;
		}
		*/

	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		//rotate 
		angle = angle + 120 * (Clock_GetDeltaTime() / 1000.f);
		if (angle > 360)
		{
			angle = angle - 360;
		}
	}


	if (GetAsyncKeyState(VK_RIGHT))
	{
		//rotate
		angle = angle - 120 * (Clock_GetDeltaTime() / 1000.f);
		if (angle < 0)
		{
			angle = angle + 360;
		}
	}

	if ((GetAsyncKeyState(VK_SPACE) && MSB) || (GetAsyncKeyState(VK_RCONTROL) && MSB))
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

	for (i = 0; i < screen_width; ++i)
	{
		for (j = 0; j < screen_height; ++j)
		{
			aScreen[i + j * screen_width] = '\0';
		}
	}
}

void collision_detection()
{
	int i, j;
	

	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{


			if (aScreen[((screen_width / 2)-i) + (((screen_height / 2)-j) * screen_width)] != '\0')
			{
				velocityX = 0;
				velocityY = 0;
			}
		}
	}


}
/*
void Draw_Screen()
{
	ClearScreen();
	int x,y;
	float newY = 0.1f, newX = 0.1f;
	
	//increase velocity by gravity value, note this does nothing for directions other than down
	//velocityY = velocityY - 0.005f* Clock_GetDeltaTime()/1000;


	//calculate translation vectors
	
	//yTrans = (float)(yTrans + (velocityY) * Clock_GetDeltaTime());
	//xTrans = (float)(xTrans + (velocityX) * Clock_GetDeltaTime());


	//firing the laser, call it first so the level overwrites it
	if (gunFired)

	{
		for (x = (screen_height / 2 - 1); x > 0; x--)
		{

			aScreen[(screen_width / 2) + x * screen_width] = '|';


		}
	}

	// take the fixed aLevel array, translate and rotate it based on current positions and angles, then copy it into aScreen array ready to render.
	int xAdjust = screen_width / 2;
	int yAdjust =screen_height / 2;
	for (y = 0; y < level_height; ++y)
	{
		for (x = 0; x < level_width; ++x)
		{
			if (aLevel[x + y * level_width] != '\0')
			{
				


				newY = (float)(((x + xTrans - xAdjust) * sin(anglerad)) + ((y + yTrans - yAdjust) * cos(anglerad)) + yAdjust);
				newX = (float)(((x + xTrans - xAdjust) * cos(anglerad)) - ((y + yTrans - yAdjust) * sin(anglerad)) + xAdjust);

				if (newY > 0 && newX > 0 && newY <= (screen_height-1) && newX <= (screen_width-1))
				{

					aScreen[(int)floor(newX) + (int)floor(newY) * screen_width] = aLevel[x + y * level_width];
				}
			}

		}
	}
	 collision_detection();

	//Draw the rocket

	aScreen[(screen_width/2) + (screen_height/2) * (screen_width)] = '^';
	aScreen[(screen_width / 2) + (screen_height / 2 +1) * (screen_width)] = 'O';
	aScreen[(screen_width / 2 -1) + (screen_height / 2 +2) * (screen_width)] = '/';
	aScreen[(screen_width / 2 +1) + (screen_height / 2 + 2) * (screen_width)] = '\\';


	//Only draw the flame when we accelerate
	if (pressed > 0)
	{
		aScreen[(screen_width/2) + (screen_height/2+2) * screen_width] = '!';

	}



	



}
*/
void Update_positions()
{

	anglerad = (angle * 3.1415 / 180.f);
	yTrans = (float)(yTrans + (velocityY)*Clock_GetDeltaTime());
	xTrans = (float)(xTrans + (velocityX)*Clock_GetDeltaTime());
	velocityY = velocityY - 0.005f * Clock_GetDeltaTime() / 1000;


}









int main()
{


	Game_Init(screen_width, screen_height);
	 
	
	
	acceleration = 0.007f * Clock_GetDeltaTime() / 1000;

	Level_Generator(aLevel, level_width, level_height, 30);
	Level_Generator(aLevel, level_width, level_height, 120);
	Level_Generator(aLevel, level_width, level_height, 300);
	Level_Generator(aLevel, level_width, level_height, 500);


	while (bGameIsRunning)
	{
		Clock_GameLoopStart();
		Update_positions();
		Get_Inputs2();

		//Draw_Screen();
		
		Draw_Screen2(xTrans, yTrans, angle, level_width, level_height, screen_width, screen_height, aLevel, aScreen, pressed, gunFired);
		

		RenderScene(aScreen, screen_width , screen_height);
		
	}
	GameShutdown();
}
