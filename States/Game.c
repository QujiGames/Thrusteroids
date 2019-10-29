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


//*********************************************************************************
//								LOCAL VARIABLES
//*********************************************************************************
static int	SelectedMenu = 0;


//*********************************************************************************
//									INPUT
//*********************************************************************************
void Game_ProcessInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		StateMachine_ChangeState(State_GameOver);
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************
void Game_Update()
{

}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void Game_Render()
{
	int y = 0;
	Console_SetRenderBuffer_String(0, y++, "GAME");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "The game is running here");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "Press >Escape< to GameOver");
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
