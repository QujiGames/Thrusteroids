#include "Global.h"
#include <Windows.h>


//*********************************************************************************
//								PROGRAM EXIT SYSTEM
//*********************************************************************************

static bool gExitRequested = false;

void Global_Exit()
{
	gExitRequested = true;
}

bool Global_IsGameRunning()
{
	return (gExitRequested == false);
}
