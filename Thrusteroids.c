﻿#include <Windows.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "Engine.h"
#include "Clock/Clock.h"
#include "Random/Random.h"
#include "Console/Console.h"
#include "ProceduralGeneration.h"
#include "Enemies.h"
#include "Global.h"
#include "StateMachine.h"


static char aBlob[1000000];
static char aLevel[1000000];
static char aScreen[25600];
static char aActors[1000000];

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
static int xblob = 1000;
static int yblob = 1000;
static int level_width = 1000; //change array size
static int level_height = 1000; //change array size
static int screen_width = 160; //change array size
static int screen_height = 160;  //change array size
const float Gravity = -0.000f;
static int score = 0;
static int lives = 3;

static double aBullets[50000];
static int bullets_fired = 0;  // 0 x position, 1 y position, 2 x vel, 3 y vel 4 bullet type
static int fire = 0;
static double fire_time = 0;


//enemies

static double aCruisers[1000];  // array for cruisers 1 = x pos, 2 = y pos, 3 = x vel, 4 = y vel, 5 = bool for isalive



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


void Game_Init(int width, int height, double(*bulletArray))
{
	Console_Init();
	Random_Init();

	Console_SetTitle("Thrusteroids 0.1");

	Console_SetSquareFont();
	Console_SetWindowedMode(width, height, false);
	Console_SetCursorVisibility(0);
	Console_CreateRenderBuffer();
	Console_SetWindowPos(800, 0);
	ClearScreen(bulletArray, 50000, 1);
	
	


}



void Game_Reset()
{
	
	velocityX = 0;
	velocityY = 0;
	angle = 0;
	ClearScreen(aBullets, 50000, 1);
	fire_time = Clock_GetElapsedTimeMs() / 100;
	int i = Generate_valid_location(level_width, level_height, aLevel);
	xTrans = -i % level_width + (screen_width / 2);
	yTrans = (-i - xTrans) / level_width + (screen_height / 2);


}






void Get_Inputs()
{
	
	
	if ((GetAsyncKeyState(VK_UP) && MSB) || (GetAsyncKeyState(0x57) && MSB))
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		
	
		
		
		acceleration = (0.01 * Clock_GetDeltaTime()) / 1000;

		velocityY = velocityY + (acceleration) * cos(anglerad);
		velocityX = velocityX + (acceleration * sin(anglerad));
		velocityY = velocityY - (Gravity * Clock_GetDeltaTime()/1000);
	
		pressed = 1;
		
		
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
		pressed = 0;
		
		
		

	}


	if (((GetAsyncKeyState(VK_UP) && MSB) || (GetAsyncKeyState(0x57) && MSB)) && (GetAsyncKeyState(0x46)))
	{
		//boost speed!!!
		acceleration = (0.05 * Clock_GetDeltaTime()) / 1000;
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
		
			if (aBullets[0 + i * 5] == '\0')
			{
				if (angle > 0 && angle < 90)
				{
					aBullets[0 + i * 5] = (double)-xTrans -1 + screen_width / 2;
					aBullets[1 + i * 5] = (double)-yTrans +1+ screen_height / 2;
					aBullets[2 + i * 5] = -velocityX - 0.05 * sin(anglerad);
					aBullets[3 + i * 5] = -velocityY - 0.05 * cos(anglerad);
					aBullets[4 + i * 5] = 1;
				}
				else if (angle >=90 && angle <180)
				{
					aBullets[0 + i * 5] = (double)-xTrans-1 + screen_width / 2;
					aBullets[1 + i * 5] = (double)-yTrans +1+ screen_height / 2;
					aBullets[2 + i * 5] = -velocityX - 0.05 * sin(anglerad);
					aBullets[3 + i * 5] = -velocityY - 0.05 * cos(anglerad);
					aBullets[4 + i * 5] = 1;
				}
				else if(angle >=180 && angle <270)

				{
					aBullets[0 + i * 5] = (double)-xTrans +1 + screen_width / 2;
					aBullets[1 + i * 5] = (double)-yTrans +1+ screen_height / 2;
					aBullets[2 + i * 5] = -velocityX - 0.05 * sin(anglerad);
					aBullets[3 + i * 5] = -velocityY - 0.05 * cos(anglerad);
					aBullets[4 + i * 5] = 1;
				}
				else
				{
					aBullets[0 + i * 5] = (double)-xTrans +1 + screen_width / 2;
					aBullets[1 + i * 5] = (double)-yTrans -1 + screen_height / 2;
  					aBullets[2 + i * 5] = -velocityX - 0.05 * sin(anglerad);
					aBullets[3 + i * 5] = -velocityY - 0.05 * cos(anglerad);
					aBullets[4 + i * 5] = 1;
				}



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


	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		StateMachine_ChangeState(State_GameOver);

	
}
void Draw_Bullets()
{
	int x, y, i;

   	for (i = 0; i < 10000; i++)
	{
		
		aBullets[0 + (i * 5)] = aBullets[0 + (i * 5)] + aBullets[2 + (i * 5)] * Clock_GetDeltaTime();
		aBullets[1 + (i * 5)] = aBullets[1 + (i * 5)] + aBullets[3 + (i * 5)] * Clock_GetDeltaTime();

		x = (int)aBullets[0 + (i * 5)];
		y = (int)aBullets[1 + (i * 5)];

 		if (x > 0 && x < level_width && y > 0 && y < level_height)
		{
			if (aBullets[4 + (i * 5)] == 1)
			{
				aActors[x + y * level_width] = 'o';
			}
			else if (aBullets[4 + (i * 5)] == 2)
			{
				aActors[x + y * level_width] = 'O';
			}

		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				aBullets[j + (i * 5)] = '\0';
			//	bullets_fired--;
			}
		}

	}
}





void collision_detection()
{
	int i, j;
	//detect if something hits the ship
	
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			// landing collision

			if (aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != '\0'  
				&& aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != '+'
				&& aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != '.'
				&& aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != '*'
				&& aScreen[((screen_width / 2) - i) + (((screen_height / 2) - j) * screen_width)] != 'o')
			{
				if (angle < 20 || angle >340)
				{
					
				}

				//anything else at the centre of the screen is a bad collision and kill us

				else
				{
					Console_SetRenderBuffer_String(screen_width / 2, screen_height / 2, "You died");
					
					if (lives > 0)
					{
						Game_Reset();
						lives--;
					}
					else
					{

						StateMachine_ChangeState(State_GameOver);
						lives = 3;
					}


				}


				
			}
		}
	}
	




	//detect if bullets hit the walls and delete them

	for (int i = 0; i < 10000; i++)
	{
		int x = (int)aBullets[i * 5];
		int y = (int)aBullets[1 + i * 5];

		if (aLevel[x + y * level_width] != '\0' && aLevel[x + y * level_width] != '*' && aLevel[x + y * level_width] != '.' && aLevel[x + y * level_width] != '+')
		{
			aBullets[0 + i * 5] = '\0';
				aBullets[1 + i * 5] = '\0';
				aBullets[2 + i * 5] = '\0';
				aBullets[3 + i * 5] = '\0';
		}
	}
	
			
			

	//detect if bullets hit ships and delete them
	
	for (int i = 0; i < 10000; i++)
	{
		int x = aBullets[i * 5];
		int y = aBullets[1 + i * 5];


		for(j = -1;j<2;j++)
		{
			for (int k = -1; k < 2; k++)
			{
				
				
				if (aBullets[4 + i * 5] == 1)
					
					{
					if (aActors[(x + k) + ((y + j) * level_width)] == '1')
						{
							aBullets[0 + i * 5] = '\0';
    						aBullets[1 + i * 5] = '\0';
							aBullets[2 + i * 5] = '\0';
							aBullets[3 + i * 5] = '\0';

               							Destroy_Cruiser(aCruisers, x, y, &score);
										//score = score + 10;
						}
					}
				
			}
		}
		
	}
	
}





void Draw_Actors()

{
	
	Cruiser_AI(aCruisers, aLevel, -xTrans + screen_width / 2, -yTrans + screen_height / 2, level_width);
	//Draw_STAR(aLevel, aActors, 60, 60, level_height, level_width, Clock_GetElapsedTimeMs(), 0,20, 50);
	
	//Draw_STAR(aLevel, aActors, 120, 120, level_height, level_width, Clock_GetElapsedTimeMs(), 30, 80,-100);





	// 
	// compare elapsed time with a temporary holder to see when 2s has passed, call funciton with different values to trigger firing
	//

	if ((Clock_GetElapsedTimeMs() / 10 - fire_time) > 100)

	{
		fire = 1;
		
		if ((Clock_GetElapsedTimeMs() / 10 - fire_time) > 101)
		{
			
			fire_time = Clock_GetElapsedTimeMs() / 10;
		}
	}
	else
	{
		fire = 0;
	}

	int i;
	for (i = 1; i < 5; i++)
	{
		Create_Cruiser(Generate_valid_location(level_width, level_height, aLevel), level_width, aCruisers, i);
	}

	

	for (i = 4; i < 1000; i += 5)
	{
		if (aCruisers[i] == 1 && aCruisers[i-4] >5)
		{
			aCruisers[i - 4] = aCruisers[i - 4] + aCruisers[i - 2] * Clock_GetDeltaTime();
			aCruisers[i - 3] = aCruisers[i - 3] + aCruisers[i - 1] * Clock_GetDeltaTime();
			
			
			if (fire == 1)
			{

				Draw_Cruiser(aActors, aCruisers[i-4], aCruisers[i-3], level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2), 1, aCruisers);
				
			}


			else

			{
				Draw_Cruiser(aActors, aCruisers[i - 4], aCruisers[i - 3], level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2), 0, aCruisers);
			}
		}
	}

	//Draw_Cruiser(aActors, 100, 100, level_width, level_height, 0, 0, Clock_GetDeltaTime(), aBullets, &bullets_fired, (-xTrans + screen_width / 2), (-yTrans + screen_height / 2));
	
}


void Update()
{
	
	
	
	
//collision_detection();
	anglerad = (angle * 3.1415 / 180);
	yTrans = (float)(yTrans + (velocityY)*Clock_GetDeltaTime());
	xTrans = (float)(xTrans + (velocityX)*Clock_GetDeltaTime());
	

	Draw_Actors();
	Draw_Bullets();
	Draw_Screen(xTrans, yTrans, angle, level_width, level_height, screen_width, screen_height, aLevel, aScreen, aActors, pressed, gunFired, lives);

	ClearScreen(aActors, level_width, level_height);


}










int main()
{

	Game_Init(screen_width, screen_height, aBullets);


	//
	//	Comment the statemachine line below out if you want to see the game
	//
	StateMachine_ChangeState(State_LoadingScreen);


	acceleration = 0.00f * Clock_GetDeltaTime() / 1000;

	//Level_Generator2(aLevel, level_width, level_height, screen_width, screen_height, &xTrans, &yTrans, 30);

	Blob_Generator(aBlob, aLevel, xblob, yblob, level_width, level_height);

	int i = Generate_valid_location(level_width, level_height, aLevel);
	xTrans = -i % level_width + (screen_width/2);
	yTrans = (-i - xTrans) / level_width + (screen_height/2);



	while (Global_IsGameRunning())
	{
		//
		//	uncomment these for the game
		//
		
		Clock_GameLoopStart();
		//Get_Inputs();
		//Update();




		//
		//	uncomment renderscene below to see the game
		//
		//RenderScene(aScreen, screen_width, screen_height, score, angle, acceleration, velocityX, velocityY, lives);




		//
		//	Comment these statemachine lines below out if you want to see the game
		//
		StateMachine_StartFrame();
		StateMachine_ProcessInput();
		StateMachine_Update();
		StateMachine_Render(aScreen, screen_width, screen_height, score, angle, acceleration, velocityX, velocityY, lives);


	}

	Console_CleanUp();

}
	

	/*

	while (bGameIsRunning)
	{
		
		//
		//Draws ASCII characters table, ignore otherwise
		//
		
		
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

