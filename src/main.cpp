#include <raylib.h>
#include "constants.h"
#include "game_logic.h"
#include "field.h"
#include <iostream>

using namespace constants;

int main() {
    // Window size constants.
    const int screen_width = 800, screen_height = 800;

    // Initiаlizing window and setting FPS.
    InitWindow(screen_width, screen_height, "TicTacToe");
    SetTargetFPS(60);

    // Loading textures.
    Texture2D field_texture = LoadTexture(field_texture_path.data());
    Texture2D o_texture = LoadTexture(o_texture_path.data());
    Texture2D x_texture = LoadTexture(x_texture_path.data());
    
    // Creating field class.
    const std::array<Texture2D, 3> textures = {field_texture, x_texture, o_texture};
    Field field(textures, 
                Vector2 {(screen_width - field_size) / 2, (screen_width - field_size) / 2}, 
               global_scale);
    // Creating game logic class.
    GameLogic game;

    const Vector2 field_position = field.get_position();

    // This matrix represents symbols positions
    std::array<std::array<Vector2, 3>, 3> symbols_positions = {{
        {{
            Vector2 {field_position.x, field_position.y}, 
            Vector2 {field_position.x + (symbol_size + gap), field_position.y},
            Vector2 {field_position.x + (symbol_size + gap) * 2, field_position.y}, 
        }},
        {{
            Vector2 {field_position.x, field_position.y + (symbol_size + gap)},
            Vector2 {field_position.x + (symbol_size + gap), field_position.y + (symbol_size + gap)},
            Vector2 {field_position.x + (symbol_size + gap) * 2, field_position.y + (symbol_size + gap) },
        }},
        {{
            Vector2 {field_position.x, field_position.y + (symbol_size + gap) * 2},
            Vector2 {field_position.x + (symbol_size + gap), field_position.y + (symbol_size + gap) * 2},
            Vector2 {field_position.x + (symbol_size + gap) * 2, field_position.y + (symbol_size + gap) * 2},
        }}
    }};


    bool window_should_close = false;
    while (!window_should_close)
    {
        // Logic
        window_should_close = WindowShouldClose();
        std::pair<int, int> player_move = game.get_player_move((symbol_size + gap), symbols_positions);
        if (player_move.first != -1 && player_move.second != -1) {
            field.add_to_field(player_move, game.plays_o() ? 'O' : 'X');
            game.swap_players();
        }
        FieldState field_state = field.check_field();
        if (field_state != FieldState::NONE) window_should_close = true;
        // Drawing
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            field.draw(symbols_positions);
        }
        EndDrawing();
    }

    // Closing window.
    CloseWindow();
    return 0;
}
