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
void Instructions_ProcessInput()
{
	if (GetAsyncKeyState(VK_RETURN) & 1)
		StateMachine_ChangeState(State_Game);

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		Global_Exit();
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************

void Instructions_Update()
{
}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void Instructions_Render()
{
	int x = 20;
	int y = 40;
	stars();

	char text[] = "INSTRUCTIONS";

	Write_Text(x, y, text);

	Console_SetRenderBuffer_String(50, 80, "Press >Enter< to Play");
	Console_SetRenderBuffer_String(50, 85, "Press >Escape< to Quit the program");
}



//*********************************************************************************
//								STATE MANAGEMENT
//*********************************************************************************
void Instructions_EnterState()
{
}

void Instructions_ExitState()
{
}
