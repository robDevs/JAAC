#include "common.h"


int main()
{
  // Initialization
    //--------------------------------------------------------------------------------------
    init();

    loadTextures();
    

    const char msg1[50] = "Hello World";

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);

            DrawText(msg1, 20*scaleX, 20*scaleY, 20*scaleY, BLACK);
            DrawText(FormatText("%dx%d", GetMouseX(), GetMouseY()), 20*scaleX, 40*scaleY, 20*scaleY, BLACK);
            DrawText(FormatText("%dx%d", GetScreenWidth(), GetScreenHeight()), 20*scaleX, 60*scaleY, 20*scaleY, BLACK);
            DrawText(FormatText("Scale x: %lf \tscale y: %lf", scaleX, scaleY), 20*scaleX, 80*scaleY, 20*scaleY, BLACK);

            DrawTexture(textures[brick_5], 200*scaleX, 100*scaleY, WHITE);
            

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