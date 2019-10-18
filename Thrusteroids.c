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
}

void Draw_Screen()
{

	int i;
	for (i = 0; i < 1600; i++)
	{
		aScreen[i] = aLevel[i];
	}

	velocity = velocity * acceleration;
	PlayerY = PlayerY + velocity * Clock_GetDeltaTime();



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

}
