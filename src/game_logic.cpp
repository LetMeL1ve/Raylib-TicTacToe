#include "game_logic.h"

std::pair<int, int> GameLogic::get_player_move(const int symbol_size, std::array<std::array<Vector2, 3>, 3>& symbols_positions) {
    for (int y = 0; y != 3; y++) {
        for (int x = 0; x != 3; x++) {
            Rectangle rec = {
                symbols_positions.at(y).at(x).x, symbols_positions.at(y).at(x).y,
                symbol_size, symbol_size};
            if (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                return {x, y};
        }
    }
    return {-1, -1};
}