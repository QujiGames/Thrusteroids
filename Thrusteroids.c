#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>
#include "Game.h"
#include "Engine.h"
#include "Clock/Clock.h"
#include <math.h>
#include "ProceduralGeneration.h"
#include "Enemies.h"


static int bGameIsRunning = 1;
static char aLevel[160000];
static char aScreen[25600];
static char aActors[160000];

static double velocityY = 0.000f;
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
static int level_width = 400; //change array size
static int level_height = 400; //change array size
static int screen_width = 160; //change array size
static int screen_height = 160;  //change array size
const float Gravity = -0.000f;
int score = 0;

static double aBullets[40000];
static int bullets_fired = 0;
static int fire = 0;
static double fire_time = 0;


/******************************************************************************
*******************************************************************************
*******************************************************************************
*******
*******		//	List of locations of various methods (does not include Console.c | Random.c | Clock.cpp):
*******				
*******			
*******			Method Name							Method Location						Status
*******																					
*******			Get_Inputs():						Thrusteroids.c						Called
*******			Draw_Bullets():						Thrusteroids.c						Called
*******			collision_detection():				Thrusteroids.c						Called
*******			Draw_Actors():						Thrusteroids.c						Called
*******			Update():							Thrusteroids.c						Called
*******			main():								Thrusteroids.c						Called
*******
*******			Game_Init():						Game.c								Called
*******			Make_Level():						Game.c								NOT Called (Deprecated?)
*******			GameShutdown():						Game.c								Called
*******
*******			Level_Seed():						ProceduralGeneration.c				Called
*******			Bounding_Box():						ProceduralGeneration.c				Called
*******			Draw_Wall():						ProceduralGeneration.c				Called
*******			Draw_Wall2():						ProceduralGeneration.c				NOT Called (Deprecated?)
*******			Draw_Wall3():						ProceduralGeneration.c				Called
*******			Level_Constructor():				ProceduralGeneration.c				Called (in progress)
*******			Wall_Unit():						ProceduralGeneration.c				Called (in progress)
*******			Level_Generator():					ProceduralGeneration.c				NOT Called (Deprecated?)
*******			Star_Field():						ProceduralGeneration.c				Called
*******			Level_Generator2():					ProceduralGeneration.c				Called
*******
*******			Draw_STAR():						Enemies.c							NOT Called (commented out, assume future use)
*******			Draw_Cruiser():						Enemies.c							Called
*******			Place_Cruiser():					Enemies.c							Called
*******
*******			RenderScene():						Engine.c							Called
*******			ClearScreen():						Engine.c							Called
*******			Draw_Screen():						Engine.c							Called
*******
*******
*******
*******		//	Structure of Game Loop (does not include Console.c | Random.c | Clock.cpp methods):	
*******
*******			main() calls:
*******						Game_Init() calls:
*******									ClearScreen()
*******
*******						Level_Generator2() calls:
*******									Bounding_Box()
*******									Draw_Wall3()
*******									Draw_Wall()
*******									Level_Constructor()
*******									Star_Field()
*******
*******						Get_Inputs()
*******
*******						Update() calls:
*******									Draw_Actors() calls:
*******												Draw_STAR()
*******												Draw_Cruiser()
*******									Draw_Bullets()
*******									Draw_Screen() calls:
*******												ClearScreen()
*******												Place_Cruiser()
*******									ClearScreen()
*******
*******						RenderScene()
*******
*******						GameShutdown()
*******
*******
*******************************************************************************
*******************************************************************************
*******************************************************************************/




void Get_Inputs()
{
	
	
	if ((GetAsyncKeyState(VK_UP) && MSB) || (GetAsyncKeyState(0x57) && MSB))
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		
	
		
		
		acceleration = (0.01 * Clock_GetDeltaTime()) / 1000;

		velocityY = velocityY + (acceleration) * cos(anglerad);
		velocityX = velocityX + (acceleration * sin(anglerad));
		velocityY = velocityY - (Gravity * Clock_GetDeltaTime()/1000);
	
			
		
		
	}
	
	else
	{
		acceleration = Gravity * Clock_GetDeltaTime() / 1000;
		velocityY = velocityY + (acceleration);
		
		
		if (velocityX > 0)
		{
			velocityX = velocityX + (acceleration * 2);

		}
		else if (velocityX < 0)
		{
			velocityX = velocityX - (acceleration * 2);


		}
			
		
		
		

	}


	if (((GetAsyncKeyState(VK_UP) && MSB) || (GetAsyncKeyState(0x57) && MSB)) && (GetAsyncKeyState(0x46)))
	{
		//boost speed!!!
		acceleration = (0.03 * Clock_GetDeltaTime()) / 1000;
		velocityY = velocityY + (acceleration)*cos(anglerad);
		velocityX = velocityX + (acceleration * sin(anglerad));


	}








	if ((GetAsyncKeyState(VK_LEFT)) || (GetAsyncKeyState(0x41)))
	{
		//rotate 
		angle = angle + 120 * (Clock_GetDeltaTime() / 1000.f);
		if (angle > 360)
		{
			angle = angle - 360;
		}
	}


	if ((GetAsyncKeyState(VK_RIGHT)) || (GetAsyncKeyState(0x44)))
	{
		//rotate
		angle = angle - 120 * (Clock_GetDeltaTime() / 1000.f);
		if (angle < 0)
		{
			angle = angle + 360;
		}
	}

	if ((GetAsyncKeyState(VK_SPACE)) || (GetAsyncKeyState(VK_RCONTROL)))
	{
		// check for space bar pressed to fire laser
		
		
		gunFired = 0;

		// fill out bullet array, position 1 = x, 2 = y, 3 = x velocity, 4 = y velocity
		
		for(int i = 0; i<10000; i++)
		
			if (aBullets[0 + i * 4] == '\0')
			{
				aBullets[0 + i * 4] = -xTrans + screen_width / 2;
 				aBullets[1 + i * 4] = -yTrans + screen_height / 2;
				aBullets[2 + i * 4] = -velocityX - 0.05 * sin(anglerad);
				aBullets[3 + i * 4] = -velocityY - 0.05 * cos(anglerad);

				//bullets_fired++;
				i = 10000;     

			}
		
	}
	else 
	{
		gunFired = 0;
	}

	if ((GetAsyncKeyState(0x50)) || (GetAsyncKeyState(0x45)))
	{
		// check for space bar pressed to fire laser

		velocityX = 0;
		velocityY = 0;


	}
	
}
void Draw_Bullets()
{
	int x, y, i;

   	for (i = 0; i < 10000; i++)
	{
		
		aBullets[0 + (i * 4)] = aBullets[0 + (i * 4)] + aBullets[2 + (i * 4)] * Clock_GetDeltaTime();
		aBullets[1 + (i * 4)] = aBullets[1 + (i * 4)] + aBullets[3 + (i * 4)] * Clock_GetDeltaTime();

		x = aBullets[0 + (i * 4)];
		y = aBullets[1 + (i * 4)];

 		if (x > 0 && x < level_width && y > 0 && y < level_height)
		{
 			aActors[x + y * level_width] = (char)207;
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				aBullets[j + (i * 4)] = '\0';
			//	bullets_fired--;
			}
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


			if (aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != '\0')
			{
				if (angle < 20 || angle >340)
				{
					velocityX = 0;
					velocityY = 0;
				}

				else
				{
					Console_SetRenderBuffer_String(screen_width / 2, screen_height / 2, "You died");
					velocityX = 0;
					velocityY = 0;
				}


				
			}
		}
	}


}





void Draw_Actors()

{
	
	//Draw_STAR(aLevel, aActors, 60, 60, level_height, level_width, Clock_GetElapsedTimeMs(), 0,20, 50);
	
	//Draw_STAR(aLevel, aActors, 120, 120, level_height, level_width, Clock_GetElapsedTimeMs(), 30, 80,-100);





	// 
	// compare elapsed time with a temporary holder to see when 2s has passed, call funciton with different values to trigger firing
	//

	if ((Clock_GetElapsedTimeMs() / 100 - fire_time) > 20)

	{
		fire = 1;
		
		if ((Clock_GetElapsedTimeMs() / 100 - fire_time) > 21)
		{
			
			fire_time = Clock_GetElapsedTimeMs() / 100;
		}
	}
	else
	{
		fire = 0;
	}

	if (fire == 1)
	{
		Draw_Cruiser(aActors, 80, 100, level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2), 1);
	}
	else

	{
		Draw_Cruiser(aActors, 80, 100, level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2), 0);

	}

	//Draw_Cruiser(aActors, 100, 100, level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2));
	
}


void Update()
{
	

	
	

	anglerad = (angle * 3.1415 / 180);
	yTrans = (float)(yTrans + (velocityY)*Clock_GetDeltaTime());
	xTrans = (float)(xTrans + (velocityX)*Clock_GetDeltaTime());
	

	Draw_Actors();
	Draw_Bullets();
	Draw_Screen(xTrans, yTrans, angle, level_width, level_height, screen_width, screen_height, aLevel, aScreen, aActors, pressed, gunFired);

	ClearScreen(aActors, level_width, level_height);


}










int main()
{


	Game_Init(screen_width, screen_height);
	 
	
	
	acceleration = 0.00f * Clock_GetDeltaTime() / 1000;

	Level_Generator2(aLevel, level_width, level_height, screen_width, screen_height, &xTrans, &yTrans, 30);


	
	while (bGameIsRunning)
	{
		Clock_GameLoopStart();
		
		Get_Inputs();
		Update();
		
		
		
		

		RenderScene(aScreen, screen_width , screen_height, score, angle, acceleration, velocityX, velocityY);
		
		
	}


	/*
	
	Draws ASCII characters table, ignore otherwise



	while (bGameIsRunning == 2)
	{
		Clock_GameLoopStart();

		Get_Inputs();
		Update();

		Console_ClearRenderBuffer();

		int counter = 0;
		char aSymbols[400];
		for (int i = 0; i < 256; i++)
		{
			aSymbols[i] = 'i';
		}
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				snprintf(aSymbols, 256, "%d", counter);
				Console_SetRenderBuffer_String((j + 1) * 8, (i + 1) * 5, aSymbols);
				Console_SetRenderBuffer_String((j + 1) * 8 + 3, (i + 1) * 5, ": ");
				


				Console_SetRenderBuffer_Char((j + 1) * 8 + 5, (i + 1) * 5, (char)(counter), 0x0001, 0x0004, 0x0002);
				counter++;
			}
		}

	


		Console_SwapRenderBuffer();


	}
	*/



	GameShutdown();
}
