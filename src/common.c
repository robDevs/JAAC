#include "common.h"

void init()
{
  screenWidth = 800;
  screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Just Another Arkanoid Clone");
  ToggleFullscreen();

  if (!WindowShouldClose())  //not sure why but this is the only way I can make scale work. 
    {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      EndDrawing();
      scaleX = GetScreenWidth()/(double)screenWidth;
      scaleY = GetScreenHeight()/(double)screenHeight;
    }
}

void loadTextures()
{
  loadAndResize(&textures[0], "images/ball_anim_1.png");
  loadAndResize(&textures[1], "images/ball_anim_2.png");
  loadAndResize(&textures[2], "images/ball_anim_3.png");
  loadAndResize(&textures[3], "images/ball_anim_4.png");
  loadAndResize(&textures[4], "images/ball.png");
  loadAndResize(&textures[5], "images/brick_1.png");
  loadAndResize(&textures[6], "images/brick_2.png");
  loadAndResize(&textures[7], "images/brick_3.png");
  loadAndResize(&textures[8], "images/brick_4.png");
  loadAndResize(&textures[9], "images/brick_5.png");
  loadAndResize(&textures[10], "images/brick_extra_1.png");
  loadAndResize(&textures[11], "images/brick_extra_2.png");
  loadAndResize(&textures[12], "images/brick_extra_3.png");
  loadAndResize(&textures[13], "images/brick_extra_4.png");
  loadAndResize(&textures[14], "images/brick_extra_5.png");
  loadAndResize(&textures[15], "images/brick_extra_6.png");
  loadAndResize(&textures[16], "images/lives_1.png");
  loadAndResize(&textures[17], "images/lives_2.png");
  loadAndResize(&textures[18], "images/lives_3.png");
  loadAndResize(&textures[19], "images/lives_4.png");
  loadAndResize(&textures[20], "images/lives_5.png");
  loadAndResize(&textures[21], "images/paddle_long.png");
  loadAndResize(&textures[22], "images/paddle.png");
  loadAndResize(&textures[23], "images/particles.png");
}

void loadAndResize(Texture2D* texture, const char *src)
{
  Image temp = LoadImage(src);
  ImageResize(&temp, temp.width*scaleX, temp.height*scaleY);
  *texture = LoadTextureFromImage(temp);
  UnloadImage(temp);
}

void cleanUpTextures()
{
  for(int i = 0; i < 24; i++)
  {
    UnloadTexture(textures[i]);
  }
}