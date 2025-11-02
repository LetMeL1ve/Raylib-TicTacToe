#include "field.h"
#include <iostream>

void Field::draw(std::array<std::array<Vector2, 3>, 3>& symbols_positions) {
    // Getting texture size
    const int size = this->textures.at(0).width;

    // Creating rectangels for DrawTexturePro fucntion.
    Rectangle source = {0, 0, size, size};
    Rectangle dest = {position.x, position.y, size * scale, size * scale};

    DrawTexturePro(this->textures.at(0), source, dest, Vector2 {0, 0}, 0.0f, WHITE);

    // Drawing symbols inside the field
    int symbol_size = textures.at(1).height * scale;
    
    for (int y = 0; y != field_size; ++y) {
        for (int x = 0; x != field_size; ++x) {
            if (!(field.at(y).at(x) == ' '))
                draw_symbol(symbols_positions.at(y).at(x), field.at(y).at(x));
        }
    }
}
void Field::draw_symbol(Vector2 screen_position, char symbol) {
    // Getting texture size
    const int size = this->textures.at(1).width;

    // Creating rectangels for DrawTexturePro fucntion.
    Rectangle source = {0, 0, size, size};
    Rectangle dest = {screen_position.x, screen_position.y, size * scale, size * scale};

    DrawTexturePro(symbol == 'X' ? textures.at(1) : textures.at(2), source, dest, Vector2 {0, 0}, 0.0f, WHITE);
}

// Sets symbol at position at "symbol_position" to "symbol" returns true if it is OK else returns flase.
bool Field::add_to_field(std::pair<int, int> symbol_position, char symbol) {
    if (field.at(symbol_position.second).at(symbol_position.first) == ' ') {
        field.at(symbol_position.second).at(symbol_position.first) = symbol;
        return true;
    } else 
        return false;
}

void Field::get_free_cells(std::vector<std::pair<int, int>>* free_cells) {
    for (int y = 0; y != field_size; ++y) {
        for (int x = 0; x != field_size; ++x) {
            if (field.at(y).at(x) == ' ')
                free_cells->push_back({static_cast<float>(x), static_cast<float>(y)});
        }
    }
}

// Returns one of FieldState enumeration.
FieldState Field::check_field() {
    // Horizontal check
    if (field[0][0] == field[0][1] && field[0][2] == field[0][1] && field[0][0] != ' ')
    return field[0][0] == 'X' ? FieldState::XWON : FieldState::OWON;
    if (field[1][0] == field[1][1] && field[1][2] == field[1][1]  && field[1][0] != ' ')
    return field[1][0] == 'X' ? FieldState::XWON : FieldState::OWON;
    if (field[2][0] == field[2][1] && field[2][2] == field[2][1]  && field[2][0] != ' ')
    return field[2][0] == 'X' ? FieldState::XWON : FieldState::OWON;

    // Diagonal check
    if (field[0][0] == field[1][1] && field[2][2] == field[1][1]  && field[0][0] != ' ')
    return field[0][0] == 'X' ? FieldState::XWON : FieldState::OWON;
    if (field[0][2] == field[1][1] && field[2][0] == field[1][1]  && field[0][2] != ' ')
    return field[0][2] == 'X' ? FieldState::XWON : FieldState::OWON;

    // Vertical check
    if (field[0][0] == field[1][0] && field[1][0] == field[2][0]  && field[1][0] != ' ')
    return field[0][0] == 'X' ? FieldState::XWON : FieldState::OWON;
    if (field[0][1] == field[1][1] && field[1][1] == field[2][1]  && field[0][1] != ' ')
    return field[0][1] == 'X' ? FieldState::XWON : FieldState::OWON;
    if (field[0][2] == field[1][2] && field[1][2] == field[2][2]  && field[0][2] != ' ')
    return field[0][2] == 'X' ? FieldState::XWON : FieldState::OWON;

    // Draw check
    std::vector<std::pair<int, int>> free_cells;
    get_free_cells(&free_cells);
    if (free_cells.size() == 0) 
        return FieldState::DRAW;

    // Returns FieldState::NONE if none of statements above are true.
    return FieldState::NONE;
}

Field::Field(const std::array<Texture2D, 3>& ts, Vector2 p, float s) : position(p), scale(s) {
    for (int i = 0; i != 3; ++i) {
        textures.at(i) = ts.at(i);
    }
    int symbol_size = textures.at(1).width * scale + 4 * scale;
}