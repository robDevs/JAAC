#include "common.h"
#include "menu.h"
#include "game.h"


int main()
{
  // Initialization
    //--------------------------------------------------------------------------------------
    init();
    SetTargetFPS(60);

    loadTextures();

    initMenu();
    
    // Main game loop
    while (!WindowShouldClose() && !quit)    // Detect window close button or ESC key
    {
      if(state == menu) updateMenu();
      if(state == game) updateGame();

      // Draw
      //----------------------------------------------------------------------------------
      BeginDrawing();
        if(state == menu) drawMenu();
        if(state == game) drawGame();
      EndDrawing();
      //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    cleanUpTextures();
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}