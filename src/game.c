#include "game.h"

void initGame()
{
  for(int i = 0; i < 11; i++){
    for(int x = 0; x < 6; x++){
      bricks[i][x].rect.width = textures[brick_1].width; 
      bricks[i][x].rect.height = textures[brick_1].height;
      bricks[i][x].rect.x = 50*scaleX + i * textures[brick_1].width;
      bricks[i][x].rect.y = 50*scaleY + x * textures[brick_1].height;
      bricks[i][x].health = 1;
      bricks[i][x].type = 1; 
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
    balls[i].rect.y = playerRect.y - balls[i].rect.height - 2;
    balls[i].xVel = 0; 
    balls[i].yVel = 0;
    balls[i].frame = 0;
    balls[i].hitFrame = false;
  } 

  balls[0].active = true;

  score = 0;
  multiplier = 1;
  brickCount = 0;
  extraBalls = 5;
}

void updateGame()
{
  //gamepad controls
  if (IsGamepadAvailable(GAMEPAD_PLAYER1))
    {
      if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 0) == -1.00 && playerRect.x > 50*scaleX) 
      {
        playerRect.x -= 5 * scaleX;
      }

      if(GetGamepadAxisMovement(GAMEPAD_PLAYER1, 0) == 1.00 && playerRect.x + playerRect.width < 50 * scaleX + textures[brick_1].width*11) 
      {
        playerRect.x += 5 * scaleX;
      }

      if(IsGamepadButtonReleased(GAMEPAD_PLAYER1, GAMEPAD_BUFFALOSNES_BUTTON_START))
      {
        balls[0].xVel = -3*scaleX; 
        balls[0].yVel = -3*scaleY;
      }
    }

    //keyboard controls
    if(IsKeyDown(KEY_LEFT) && playerRect.x > 50*scaleX) playerRect.x -= 5*scaleX; 
    if(IsKeyDown(KEY_RIGHT) && playerRect.x + playerRect.width < 50*scaleX + textures[brick_1].width*11) playerRect.x += 5*scaleX;
    if(IsKeyReleased(KEY_SPACE) && balls[0].xVel == 0 && balls[0].yVel == 0)
    {
      balls[0].xVel = -3*scaleX; 
      balls[0].yVel = -3*scaleY;
    }

    //ball movement
    for(int i = 0; i < 4; i++)
    {
      if(!balls[i].active || balls[i].xVel == 0 && balls[i].yVel == 0)
      {
        balls[i].rect.x = playerRect.x + playerRect.width/2 - balls[i].rect.width/2;
        balls[i].rect.y = playerRect.y - balls[i].rect.height - 2;
        balls[i].xVel = 0; 
        balls[i].yVel = 0;
      }

      if(balls[i].rect.x < 50*scaleX) balls[i].xVel =3*scaleX; 
      if(balls[i].rect.x + balls[i].rect.width > 50 * scaleX + textures[brick_1].width * 11) balls[i].xVel = -3*scaleX;

      if(balls[i].rect.y < 50*scaleY) balls[i].yVel = 3*scaleY; 
      if(balls[i].rect.y + balls[i].rect.height > GetScreenHeight() - 50*scaleY) 
      {
        extraBalls -= 1;
        balls[0].rect.x = playerRect.x + playerRect.width/2 - balls[i].rect.width/2;
        balls[0].rect.y = playerRect.y - balls[i].rect.height - 2;
        balls[0].xVel = 0; 
        balls[0].yVel = 0; 
        balls[1].active = false;
        balls[2].active = false;
        balls[3].active = false;
      }

      // Might as well count the bricks while here
      balls[i].hitFrame = false;
      brickCount = 0;
      //reset ballHitframe once per frame. 
      for(int z = 0; z < 11; z++)
      {
        for(int x = 0; x < 6; x++)
        {
          if(bricks[z][x].health > 0) brickCount++;
          if(CheckCollisionRecs(balls[i].rect, bricks[z][x].rect) && bricks[z][x].health > 0 && balls[i].active && !balls[i].hitFrame)
          {
            if(balls[i].rect.y + balls[i].rect.height - 2 < bricks[z][x].rect.y) balls[i].yVel = -3*scaleY;
            else if(balls[i].rect.y + 2 > bricks[z][x].rect.y + bricks[z][x].rect.height) balls[i].yVel = 3*scaleY;
            else if(balls[i].rect.x + balls[i].rect.width/2 < bricks[z][x].rect.x) balls[i].xVel = -3*scaleX;
            else if(balls[i].rect.x + balls[i].rect.width/2 > bricks[z][x].rect.x + bricks[z][x].rect.width/2) balls[i].xVel = 3*scaleX;

            bricks[z][x].health -= 1;
            if(bricks[z][x].health > 0) score += 5 * multiplier;
            else score += 9 * multiplier;

            balls[i].hitFrame = true;
          }
        }
      }

      if(CheckCollisionRecs(balls[i].rect, playerRect) && balls[i].active)
      {
        balls[i].yVel = -3*scaleY;
      }

      balls[i].rect.x += balls[i].xVel;
      balls[i].rect.y += balls[i].yVel;

      //animate the ball
      balls[i].frameTime++;
      if(balls[i].frameTime > 60/4)
      {
        balls[i].frameTime = 0;
        balls[i].frame++;
      }
      if(balls[i].frame > 4) balls[i].frame = 0; 

    }
}

void drawGame()
{
  ClearBackground(BLACK);

  DrawRectangle(50*scaleX, 50*scaleY, textures[brick_1].width*11, GetScreenHeight() - 100*scaleY, WHITE);

  DrawText(FormatText("Score: %d", score), 50*scaleX, 50*scaleY - 20*scaleY, 20*scaleY, WHITE);

  DrawText(FormatText("Bricks: %d", brickCount), 50*scaleX, GetScreenHeight() - 50*scaleY + 20*scaleY, 20*scaleY, WHITE);

  DrawText(FormatText("Multiplier: %d", multiplier), 50*scaleX + textures[brick_1].width * 11 - MeasureText(FormatText("Multiplier: %d", multiplier), 20*scaleY), GetScreenHeight() - 50*scaleY + 20*scaleY, 20*scaleY, WHITE);

  DrawTexture(textures[paddle], playerRect.x, playerRect.y, WHITE);

  switch (extraBalls)
  {
    case 5:
      DrawTexture(textures[lives_5], 50*scaleX + textures[brick_1].width*11 - textures[lives_1].width, 50*scaleY-textures[lives_1].height, WHITE);
      break;
    case 4:
      DrawTexture(textures[lives_4], 50*scaleX + textures[brick_1].width*11 - textures[lives_1].width, 50*scaleY-textures[lives_1].height, WHITE);
      break;
    case 3:
      DrawTexture(textures[lives_3], 50*scaleX + textures[brick_1].width*11 - textures[lives_1].width, 50*scaleY-textures[lives_1].height, WHITE);
      break;
    case 2:
      DrawTexture(textures[lives_2], 50*scaleX + textures[brick_1].width*11 - textures[lives_1].width, 50*scaleY-textures[lives_1].height, WHITE);
      break;
    case 1:
      DrawTexture(textures[lives_1], 50*scaleX + textures[brick_1].width*11 - textures[lives_1].width, 50*scaleY-textures[lives_1].height, WHITE);
      break;
  
    default:
      break;
  }

  for(int i = 0; i < 11; i++)
  {
    for(int x = 0; x < 6; x++)
    {
      switch (bricks[i][x].health)
      {
        case 5:
            if(bricks[i][x].type == 0) DrawTexture(textures[brick_1], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
            if(bricks[i][x].type == 1) DrawTexture(textures[brick_extra_1], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 4:
            if(bricks[i][x].type == 0) DrawTexture(textures[brick_2], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
            if(bricks[i][x].type == 1) DrawTexture(textures[brick_extra_2], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 3:
            if(bricks[i][x].type == 0) DrawTexture(textures[brick_3], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
            if(bricks[i][x].type == 1) DrawTexture(textures[brick_extra_3], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 2:
            if(bricks[i][x].type == 0) DrawTexture(textures[brick_4], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
            if(bricks[i][x].type == 1) DrawTexture(textures[brick_extra_4], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        case 1:
            if(bricks[i][x].type == 0) DrawTexture(textures[brick_5], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
            if(bricks[i][x].type == 1) DrawTexture(textures[brick_extra_5], bricks[i][x].rect.x, bricks[i][x].rect.y, WHITE);
          break;
        default:
          break;
      }
    }
  }

  for(int i = 0; i < 4; i++)
  {
    if(balls[i].active)
    {
      switch (balls[i].frame)
      {
        case 0:
          DrawTexture(textures[ball], balls[i].rect.x, balls[i].rect.y, WHITE);
          break;
        case 1:
          DrawTexture(textures[ball_anim_1], balls[i].rect.x, balls[i].rect.y, WHITE);
          break;
        case 2:
          DrawTexture(textures[ball_anim_2], balls[i].rect.x, balls[i].rect.y, WHITE);
          break;
        case 3:
          DrawTexture(textures[ball_anim_3], balls[i].rect.x, balls[i].rect.y, WHITE);
          break;
        case 4:
          DrawTexture(textures[ball_anim_4], balls[i].rect.x, balls[i].rect.y, WHITE);
          break;      
        default:
          break;
      }
    }
  }
}