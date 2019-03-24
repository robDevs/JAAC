/*
*
*
*  robDevs
*  2019 - 03 - 24
*  JAAC
*
*
*/

#ifndef _COMMON_
#define _COMMON_

#include "raylib.h"
#include "stdbool.h"

#include <string.h>

// For Snes style buffalo classic gamepad tested on Gallium OS
#define GAMEPAD_BUFFALOSNES_BUTTON_B        1
#define GAMEPAD_BUFFALOSNES_BUTTON_A        0
#define GAMEPAD_BUFFALOSNES_BUTTON_Y        3
#define GAMEPAD_BUFFALOSNES_BUTTON_X        2
#define GAMEPAD_BUFFALOSNES_BUTTON_UP       1 //marks the axis
#define GAMEPAD_BUFFALOSNES_BUTTON_DOWN     0 // marks the axis
#define GAMEPAD_BUFFALOSNES_BUTTON_LEFT     14
#define GAMEPAD_BUFFALOSNES_BUTTON_RIGHT    15
#define GAMEPAD_BUFFALOSNES_BUTTON_START    7
#define GAMEPAD_BUFFALOSNES_BUTTON_SELECT   6
#define GAMEPAD_BUFFALOSNES_BUTTON_L        4
#define GAMEPAD_BUFFALOSNES_BUTTON_R        5

#define menu  0
#define game  1

int state;
bool quit;

double scaleX;
double scaleY;

int screenWidth;
int screenHeight;

void init();

#define ball_anim_1     0
#define ball_anim_2     1
#define ball_anim_3     2
#define ball_anim_4     3
#define ball            4
#define brick_1         5
#define brick_2         6
#define brick_3         7
#define brick_4         8
#define brick_5         9
#define brick_extra_1   10
#define brick_extra_2   11
#define brick_extra_3   12
#define brick_extra_4   13
#define brick_extra_5   14
#define brick_extra_6   15
#define lives_1         16
#define lives_2         17
#define lives_3         18
#define lives_4         29
#define lives_5         20
#define paddle_long     21
#define paddle          22
#define particles       23

Texture2D textures[24];

void loadTextures();
void loadAndResize(Texture2D* texture, const char *src);
void cleanUpTextures();

#endif
