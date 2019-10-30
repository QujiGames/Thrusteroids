#include "MainMenu.h"
#include <Windows.h>
#include "../Console/Console.h"
#include "../StateMachine.h"
#include "../Global.h"
#include <stdlib.h>



static double astars[1000];


void stars()
{



	int i, x, y;

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

	// start T
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 4, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end T

	// start H
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 11, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 19, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 12 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end H

	// start R
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 22, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + 30, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 5; i++)
	{
		Console_SetRenderBuffer_Char(x + 30, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 23 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 23 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end R

	// start U
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 33, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 41, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 34 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end U

	// start S
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + 44, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 45 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + 45 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + 44 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + 52, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end S

	// start T
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 55 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 59, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end T

	// start E
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 66, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 67 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + 67 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 67 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	//end E

	// start R
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 76, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + 84, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 5; i++)
	{
		Console_SetRenderBuffer_Char(x + 84, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 77 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 77 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end R

	// start O
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 87, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + 89 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 9; i++)
	{
		Console_SetRenderBuffer_Char(x + 95, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 6; i++)
	{
		Console_SetRenderBuffer_Char(x + 88 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end O
	
	// start I
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 98, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end I

	// start D
	for (int i = 0; i < 10; i++)
	{
		Console_SetRenderBuffer_Char(x + 101, y + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 102 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + 109, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 102 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end D

	// start S
	for (int i = 0; i < 3; i++)
	{
		Console_SetRenderBuffer_Char(x + 112, y + 1 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 7; i++)
	{
		Console_SetRenderBuffer_Char(x + 113 + i, y + 4, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + 113 + i, y, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 8; i++)
	{
		Console_SetRenderBuffer_Char(x + 112 + i, y + 9, (char)219, 0x0001, 0x0004, 0x0002);
	}
	for (int i = 0; i < 4; i++)
	{
		Console_SetRenderBuffer_Char(x + 120, y + 5 + i, (char)219, 0x0001, 0x0004, 0x0002);
	}
	// end S
	

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



