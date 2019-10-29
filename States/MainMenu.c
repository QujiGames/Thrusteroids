#include "MainMenu.h"
#include <Windows.h>
#include "../Console/Console.h"
#include "../StateMachine.h"
#include "../Global.h"

//*********************************************************************************
//								LOCAL VARIABLES
//*********************************************************************************
static int	SelectedMenu = 0;


//*********************************************************************************
//									INPUT
//*********************************************************************************
void MainMenu_ProcessInput()
{
	if (GetAsyncKeyState(VK_RETURN) & 1)
		StateMachine_ChangeState(State_Game);

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		Global_Exit();
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************

void MainMenu_Update()
{
}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void MainMenu_Render()
{
	int y = 0;
	Console_SetRenderBuffer_String(0, y++, "Main Menu");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "This is the main menu");
	Console_SetRenderBuffer_String(0, y++, "");
	Console_SetRenderBuffer_String(0, y++, "=========");
	Console_SetRenderBuffer_String(0, y++, "Press >Enter< to Play");
	Console_SetRenderBuffer_String(0, y++, "Press >Escape< to Quit the program");
}



//*********************************************************************************
//								STATE MANAGEMENT
//*********************************************************************************
void MainMenu_EnterState()
{
}

void MainMenu_ExitState()
{
}
