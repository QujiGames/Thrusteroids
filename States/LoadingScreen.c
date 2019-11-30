#include "MainMenu.h"
#include <Windows.h>
#include "../Console/Console.h"
#include "../Random/Random.h"
#include "../StateMachine.h"
#include "../Global.h"
#include <stdlib.h>
#include "../WriteText.h"


static double astars[1000];

void stars()
{
	int i;

	for (i = 0; i < 500; i+=3)
	{

		Console_SetRenderBuffer_Char((int)((astars[i] * astars[i + 2])/100) + 79, (int)((astars[i + 1] * astars[i + 2])/100) + 45, '.', 0x0001, 0x0004, 0x0002);
		astars[i + 2] = astars[i + 2] +0.2;


		if (astars[i + 2] >=100)
		{

			astars[i + 2] = 1;
		}
	}
}

//*********************************************************************************
//								LOCAL VARIABLES
//*********************************************************************************
static int	SelectedMenu = 0;


//*********************************************************************************
//									INPUT
//*********************************************************************************
void LoadingScreen_ProcessInput()
{
	if (GetAsyncKeyState(VK_RETURN) & 1)
		StateMachine_ChangeState(State_MainMenu);

	if (GetAsyncKeyState(VK_ESCAPE) & 1)
		Global_Exit();
}

//*********************************************************************************
//									UPDATE
//*********************************************************************************

void LoadingScreen_Update()
{
}


//*********************************************************************************
//									RENDER
//*********************************************************************************
void LoadingScreen_Render()
{
	int x = 20;
	int y = 40;
	stars();

	char text[] = "THRUSTEROIDS";
	//char text[] = "KWXYZ";

	Write_Text(x, y, text);


	Console_SetRenderBuffer_String(50, 80, "Press >Enter< to Play");
	Console_SetRenderBuffer_String(50, 85, "Press >Escape< to Quit the program");
}



//*********************************************************************************
//								STATE MANAGEMENT
//*********************************************************************************
void LoadingScreen_EnterState()
{
	int i;

	for (i = 0; i < 500; i += 3)
	{


		int x = Random_Range(-79, 79);

		int y = Random_Range(-44, 114);


		int z = Random_Range(1,100);

		astars[i] = x;
		astars[i + 1] = y;
		astars[i + 2] = z;

	}
}

void LoadingScreen_ExitState()
{
}



