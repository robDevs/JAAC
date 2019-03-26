#ifndef _GAME_
#define _GAME_

#include "common.h"


typedef struct Brick
{
  Rectangle rect;
  int health;
  int type;
}Brick;

typedef struct Ball
{
  Rectangle rect;
  int xVel; 
  int yVel;
  bool active;
  int frame;
  int frameTime;
  bool hitFrame;
}Ball;

Brick bricks[11][6];

Ball balls[4]; 

Rectangle playerRect;

int score;
int multiplier;
int extraBalls;

int brickCount;

void initGame();
void updateGame();
void drawGame();



#endif