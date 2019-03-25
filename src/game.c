#include "game.h"

void initGame()
{
  for(int i = 0; i < 11; i++){
    for(int x = 0; x < 6; x++){
      bricks[i][x].rect.width = textures[brick_1].width; 
      bricks[i][x].rect.height = textures[brick_1].height;
      bricks[i][x].rect.x = 50*scaleX + i * textures[brick_1].width;
      bricks[i][x].rect.y = 50*scaleY + x * textures[brick_1].height;
      bricks[i][x].health = 5;
      bricks[i][x].type = 0; 
    }
  }

  playerRect.width = textures[paddle].width;
  playerRect.height = textures[paddle].height;
  playerRect.x = GetScreenWidth()/2 - playerRect.width / 2;
  playerRect.y = GetScreenHeight()-50*scaleY - playerRect.height;

  for(int i = 0; i < 4; i++)
  {
    balls[i].active = false;
    balls[i].rect.width = textures[ball].width;
    balls[i].rect.height = textures[ball].height;
    balls[i].rect.x = playerRect.x + playerRect.width/2 - balls[i].rect.width/2;
    balls[i].rect.y = playerRect.y - balls[i].rect.height;
    balls[i].xVel = 0; 
    balls[i].Yvel = 0;
  } 

  balls[0].active = true;
}

void updateGame()
{

}

void drawGame()
{
  ClearBackground(BLACK);

  DrawRectangle(50*scaleX, 50*scaleY, textures[brick_1].width*11, GetScreenHeight() - 100*scaleY, WHITE);
  DrawTexture(textures[paddle], playerRect.x, playerRect.y, WHITE);

  for(int i = 0; i < 11; i++
  ){
    for(int x = 0; x < 6; x++)
    {
      switch (bricks[i][x].health)
      {
        case 5:
            DrawTexture(textures[brick_1], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 4:
            DrawTexture(textures[brick_2], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 3:
            DrawTexture(textures[brick_3], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 2:
            DrawTexture(textures[brick_4], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 1:
            DrawTexture(textures[brick_5], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        default:
          break;
      }
    }
  }
}