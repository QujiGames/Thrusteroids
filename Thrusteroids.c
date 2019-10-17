#include "Random/Random.h"
#include "Console/Console.h"
#include <Windows.h>
#include "Game.h"
#include "Engine.h"

static int bGameIsRunning = 1;



int main()
{

	Game_Init();
	//fuji does this work

	while (bGameIsRunning)
	{
		Console_Printf(20, 20, "I love Cabbages");
	}

}
