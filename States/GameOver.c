#include "GameOver.h"
#include <Windows.h>
#include "../Console/Console.h"
#include "../StateMachine.h"

//*********************************************************************************
//								LOCAL VARIABLES
//*********************************************************************************
static int	SelectedMenu = 0;


//*********************************************************************************
//									INPUT
//*********************************************************************************
void GameOver_ProcessInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		StateMachine_ChangeState(State_MainMenu);
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************
void GameOver_Update()
{
}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void GameOver_Render()
{
	int y = 0;
	Console_SetRenderBuffer_String(0, y++, "GAME OVER");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "Nothing here");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "Press >Escape< to exit to the Main Menu");
}



//*********************************************************************************
//								STATE MANAGEMENT
//*********************************************************************************
void GameOver_EnterState()
{
}

void GameOver_ExitState()
{
}
