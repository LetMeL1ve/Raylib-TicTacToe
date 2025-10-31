#include <raylib.h>
#include "constants.h"
#include "field.h"

int main() {
    // Window size constants.
    const int screen_width = 800, screen_height = 800;

    // Initiаlizing window and setting FPS.
    InitWindow(screen_width, screen_height, "TicTacToe");
    SetTargetFPS(60);

    // Loading textures.
    Texture2D field_texture = LoadTexture(constants::field_texture_path.data());
    Texture2D o_texture = LoadTexture(constants::o_texture_path.data());
    Texture2D x_texture = LoadTexture(constants::x_texture_path.data());
    
    float global_scale = 4; // Global scale that is used for every texture and calculating in the game.
    const int field_size = field_texture.height * global_scale;  // Calculating field size in pixels.

    // Creating field class.
    Field field(field_texture, 
                Vector2 {(screen_width - field_size) / 2, (screen_width - field_size) / 2}, 
                global_scale);


    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            field.draw();
        }
        EndDrawing();
    }

    // Closing window.
    CloseWindow();
    return 0;
}
