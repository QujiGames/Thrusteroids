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

	if ((GetAsyncKeyState(0x49)) || (GetAsyncKeyState(0x69)))
		StateMachine_ChangeState(State_Instructions);

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
	int x = 20;
	int y = 40;
	stars();

	char text[] = "THRUSTEROIDS";

	Write_Text(x, y, text);


	Console_SetRenderBuffer_String(50, 80, "Press >i< for instructions");
	Console_SetRenderBuffer_String(50, 85, "Press >Enter< to Play");
	Console_SetRenderBuffer_String(50, 90, "Press >Escape< to Quit the program");
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

