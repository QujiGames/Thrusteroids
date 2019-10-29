#ifndef STATEMACHINE_H
#define STATEMACHINE_H

typedef enum GameState
{
	State_Default,
	State_LoadingScreen,
	State_MainMenu,
	State_Instructions,
	State_Game,
	State_GameOver
} GameState;

void StateMachine_StartFrame();
void StateMachine_ChangeState(GameState newState);
void StateMachine_ProcessInput();
void StateMachine_Update();
void StateMachine_Render();

#endif // STATEMACHINE_H

