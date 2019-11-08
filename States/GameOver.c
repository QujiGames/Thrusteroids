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
	int x = 20;
	int y = 40;
	stars();

	char text[] = "GAME OVER";

	Write_Text(x, y, text);

	Console_SetRenderBuffer_String(50, 85, "Press >Escape< to exit to the Main Menu");
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
