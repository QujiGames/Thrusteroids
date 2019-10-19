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
static double PlayerY = 0.f;
static double PlayerX = 0.f;
static double acceleration = 0.001f;
const unsigned short MSB = 0x8000;
static int pressed = 0;
static float angle = 0.0f;
static int xTrans = 0;
static int yTrans = 0;
static float xMod = 0;
static float yMod = 0;
static float anglerad = 0.00000f;




void Get_Inputs2()
{
	if (GetAsyncKeyState(VK_UP) & MSB)
	{
		velocity = -0.005f;
		pressed = 1;

	}
	else
	{
		if (pressed == 1)
		{
			velocity = 0.0005f;
			pressed = 0;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{

		angle = angle - 10 * (Clock_GetDeltaTime() / 1000);
		if (angle < 0)
		{
			angle = angle + 360;
		}
	}


	if (GetAsyncKeyState(VK_LEFT))
	{

		angle = angle + 10 * (Clock_GetDeltaTime() / 1000);
		if (angle > 360)
		{
			angle = angle - 360;
		}
	}

}
void ClearScreen()
{
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
	float a = 0.1f, b = 0.1f;

	anglerad = ((double)angle * 3.1415 / 180.f);


	for (i = 0; i < 40; ++i)
	{
		for (j = 0; j < 40; ++j)
		{
			if (aLevel[j + i * 40] == '#')
			{


				a = ((i + xTrans - 20) * cos(anglerad)) - ((j + yTrans - 20) * sin(anglerad)) + 20;
				b = ((i + xTrans - 20) * sin(anglerad)) + ((j + yTrans - 20) * cos(anglerad)) + 20;

				if (a > 0 && b > 0 && a <= 39 && b <= 39)
				{

					aScreen[(int)round(b) + (int)round(a) * 40] = '#';
				}
			}

		}
	}





	//	for(i = 0; i < 1600; i++)
	//	{
	//		aScreen[i] = aLevel[i];
	//	}

	velocity = velocity * acceleration;
	anglerad = ((double)angle * 3.1415 / 180.f);
	PlayerY = PlayerY + velocity * cos(anglerad) * Clock_GetDeltaTime();
	PlayerX = PlayerX + velocity * sin(anglerad) * Clock_GetDeltaTime();


	aScreen[(int)round(PlayerX) + ((int)round(PlayerY) * 40)] = 'o';


}



int main()
{


	Game_Init();
	PlayerX = 20;
	PlayerY = 20;
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
