#include "menu.h"

void initMenu()
{
  pos = 0;
  movedUp = false;
  movedDown = false;
}

void updateMenu()
{
  //gamepad controls
  if (IsGamepadAvailable(GAMEPAD_PLAYER1))
    {
      if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 01) == -1.00 && !movedUp) 
      {
        pos--;
        movedUp = true;
      }
      else if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) != -1.00) movedUp = false;
      
      if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) == 1.00 && !movedDown) 
      {
        pos++;
        movedDown = true;
      }
      else if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 1) != 1.00) movedDown = false;
      
      if(pos < 0) pos = 3; 
      if(pos > 3) pos = 0;
      
      if(IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUFFALOSNES_BUTTON_B))
      {
        switch (pos)
        {
          case 0:
            initGame();
            state = game;
            break;
          case 1:
            break;
          case 2:
            break;
          case 3:
            quit = true; 
            break;
          default:
            break;
        }
      }
    }

    //keyboard controls
    if(IsKeyReleased(KEY_UP)) pos--; 
    if(IsKeyReleased(KEY_DOWN)) pos++;
    if(pos < 0) pos = 3; 
    if(pos > 3) pos = 0; 
    if(IsKeyReleased(KEY_ENTER))
    {
      switch (pos)
        {
          case 0:
            initGame();
            state = game;
            break;
          case 1:
            break;
          case 2:
            break;
          case 3:
            quit = true; 
            break;
          default:
            break;
        }
    }
}

void drawMenu()
{
  BeginDrawing();

  ClearBackground(WHITE);

  DrawText("Start", GetScreenWidth()/2-MeasureText("Start", 20*scaleY)/2, GetScreenHeight()/2 - 100*scaleY, 20*scaleY, BLACK);
  DrawText("Edit", GetScreenWidth()/2-MeasureText("Edit", 20*scaleY)/2, GetScreenHeight()/2 - 48*scaleY, 20*scaleY, BLACK);
  DrawText("Settings", GetScreenWidth()/2-MeasureText("Settings", 20*scaleY)/2, GetScreenHeight()/2 + 2*scaleY, 20*scaleY, BLACK);
  DrawText("Quit", GetScreenWidth()/2-MeasureText("Quit", 20*scaleY)/2, GetScreenHeight()/2 + 50*scaleY, 20*scaleY, BLACK);

  if(pos == 0) DrawTexture(textures[paddle], GetScreenWidth()/2-textures[paddle].width/2, GetScreenHeight()/2-80*scaleY, WHITE);
  if(pos == 1) DrawTexture(textures[paddle], GetScreenWidth()/2-textures[paddle].width/2, GetScreenHeight()/2-28*scaleY, WHITE);
  if(pos == 2) DrawTexture(textures[paddle], GetScreenWidth()/2-textures[paddle].width/2, GetScreenHeight()/2+22*scaleY, WHITE);
  if(pos == 3) DrawTexture(textures[paddle], GetScreenWidth()/2-textures[paddle].width/2, GetScreenHeight()/2+70*scaleY, WHITE);
}