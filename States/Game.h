#ifndef GAME_H
#define GAME_H

void Game_EnterState();
void Game_ExitState();

void Game_ProcessInput();
void Game_Update();
void Game_Render(char(*arr), int width, int height, int score, float angle, double accel, double velx, double vely, int lives);

#endif // GAME_H
