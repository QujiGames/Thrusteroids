/**********************************************************************************
* \file			StateMachine.c
* \brief		State Machine solution example for GAM 100 class
* \author		Yannick Gerber
* \version		1.0
* \date			2019
*
* \note			Course: GAM100
* \copyright	Copyright (c) 2019 DigiPen Institute of Technology. Reproduction
				or disclosure of this file or its contents without the prior
				written consent of DigiPen Institute of Technology is prohibited.
**********************************************************************************/
#include "StateMachine.h"
#include "States/LoadingScreen.h"
#include "States/Game.h"
#include "States/MainMenu.h"
#include "States/GameOver.h"
#include "States/Instructions.h"
#include "Console/Console.h"

static GameState sCurrentState = State_Default;
static GameState sRequestedState = State_Default;

// Please note that once you know Function and Pointers, we will update this code
// For now, we are using switch and direction function calls

void StateMachine_StartFrame()
{
	if (sCurrentState != sRequestedState)
	{
		// Exit CurrentState
		switch (sCurrentState)
		{
		case State_LoadingScreen:		LoadingScreen_ExitState();	break;
		case State_MainMenu:			MainMenu_ExitState();		break;
		case State_Instructions:		Instructions_ExitState();	break;
		case State_Game:				Game_ExitState();			break;
		case State_GameOver:			GameOver_ExitState();		break;
		default:						break;
		}

		// Change State
		sCurrentState = sRequestedState;

		// Enter next state CurrentState
		switch (sCurrentState)
		{
		case State_LoadingScreen:		LoadingScreen_EnterState();	break;
		case State_MainMenu:			MainMenu_EnterState();		break;
		case State_Instructions:		Instructions_EnterState();	break;
		case State_Game:				Game_EnterState();			break;
		case State_GameOver:			GameOver_EnterState();		break;
		default:						break;
		}
	}
}

void StateMachine_ChangeState(GameState newState)
{
	sRequestedState = newState;
}

void StateMachine_ProcessInput()
{
	switch (sCurrentState)
	{
		case State_LoadingScreen:		LoadingScreen_ProcessInput();	break;
		case State_MainMenu:			MainMenu_ProcessInput();		break;
		case State_Instructions:		Instructions_ProcessInput();	break;
		case State_Game:				Game_ProcessInput();			break;
		case State_GameOver:			GameOver_ProcessInput();		break;
		default:						break;
	}
}

void StateMachine_Update()
{
	switch (sCurrentState)
	{
		case State_LoadingScreen:		LoadingScreen_Update();		break;
		case State_MainMenu:			MainMenu_Update();			break;
		case State_Instructions:		Instructions_Update();		break;
		case State_Game:				Game_Update();				break;
		case State_GameOver:			GameOver_Update();			break;
		default:						break;
	}
}

void StateMachine_Render()
{
	// Clear the Rendering Buffer
	Console_ClearRenderBuffer();

	// Render the scenes in the Buffer
	switch (sCurrentState)
	{
		case State_LoadingScreen:		LoadingScreen_Render();		break;
		case State_MainMenu:			MainMenu_Render();			break;
		case State_Instructions:		Instructions_Render();		break;
		case State_Game:				Game_Render();				break;
		case State_GameOver:			GameOver_Render();			break;
		default:						break;
	}

	// Copy the Render Buffer to the Screen
	Console_SwapRenderBuffer();
}


