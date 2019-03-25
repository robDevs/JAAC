#ifndef _MENU_
#define _MENU_

#include "common.h"
#include "game.h"

int pos; 
#define posMax 3

bool movedUp;
bool movedDown;

void initMenu();
void updateMenu();
void drawMenu();

#endif