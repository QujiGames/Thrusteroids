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






void Get_Inputs()
{
	
	
	if ((GetAsyncKeyState(VK_UP) && MSB) || (GetAsyncKeyState(0x57) && MSB))
	{
		// When up key is held swap the velocity, pressed variable is to allow the next part to work on release
		
		//float y = 0.02f;
		//velocityY = y * cos(anglerad) -0.005f;
		//velocityX = y * sin(anglerad);
		
		
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
		//velocityX = velocityX + (acceleration * sin(anglerad));
		
		if (velocityX > 0)
		{
			velocityX = velocityX + (acceleration * 2);

		}
		else if (velocityX < 0)
		{
			velocityX = velocityX - (acceleration * 2);


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


		
		for(int i = 0;i<10000;i++)
		
			if (aBullets[0 + i*4] == '\0')
			{
				aBullets[0 + bullets_fired * 4] = -xTrans + screen_width / 2;
 				aBullets[1 + bullets_fired * 4] = -yTrans + screen_height / 2;
				aBullets[2 + bullets_fired * 4] = -velocityX - 0.05 * sin(anglerad);
				aBullets[3 + bullets_fired * 4] = -velocityY - 0.05 * cos(anglerad);

				bullets_fired++;
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

   	for (i = 0; i < bullets_fired; i++)
	{
		aBullets[0 + i*4] = aBullets[0 + i*4] + aBullets[2 + (i * 4)] * Clock_GetDeltaTime();
		aBullets[1+i*4] = aBullets[1+i*4] + aBullets[3+ i*4] * Clock_GetDeltaTime();

		x = aBullets[0+i*4];
		y = aBullets[1+i*4];

 		if (x > 0 && x < level_width && y >0 && y < level_height)
		{
 			aActors[x + y * level_width] = 'o';
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				aBullets[j + i*4] = '\0';
				
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



void Draw_Actors()

{
	
	//Draw_STAR(aLevel, aActors, 60, 60, level_height, level_width, Clock_GetElapsedTimeMs(), 0,20, 50);
	
	//Draw_STAR(aLevel, aActors, 120, 120, level_height, level_width, Clock_GetElapsedTimeMs(), 30, 80,-100);

	if ((Clock_GetElapsedTimeMs() / 1000 - fire_time) > 2)

	{
		fire = 1;
		fire_time = Clock_GetElapsedTimeMs() / 1000;
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
	//velocityY = velocityY + Gravity * Clock_GetDeltaTime() / 1000;

	Draw_Actors();
	Draw_Bullets();
	Draw_Screen2(xTrans, yTrans, angle, level_width, level_height, screen_width, screen_height, aLevel, aScreen, aActors, pressed, gunFired);

	ClearScreen2(aActors, level_width, level_height);


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
	GameShutdown();
}
