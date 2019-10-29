#include "Game.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../Engine.h"
#include "../Random/Random.h"
#include "../Console/Console.h"
#include "../StateMachine.h"
#include "../Thrusteroids.h"


//*********************************************************************************
//								LOCAL VARIABLES
//*********************************************************************************
static int	SelectedMenu = 0;


//*********************************************************************************
//									INPUT
//*********************************************************************************
void Game_ProcessInput()
{
	Get_Inputs();
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************
void Game_Update()
{
	Update();
}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void Game_Render(char(*arr), int width, int height, int score, float angle, double accel, double velx, double vely, int lives)
{
	RenderScene(arr, width, height, score, angle, accel, velx, vely, lives);
}


//*********************************************************************************
//								STATE MANAGEMENT
//*********************************************************************************
void Game_EnterState()
{
}

void Game_ExitState()
{
}
