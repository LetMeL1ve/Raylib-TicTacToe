#include <raylib.h>
#include <array>
#include <vector>

// field_t is alias for type that is used for game_field representation.
using field_t = std::array<std::array<char, 3>, 3>;

enum class FieldState {
    NONE,
    DRAW,
    XWON,
    OWON
};
// This class represents game field.
class Field {
private: 
    // First is field texture, second X texture nad third is O texture.
    std::array<Texture2D, 3> textures;
    Vector2 position;
    float scale;
    field_t field = {{
        {{' ', ' ', ' '}},
        {{' ', ' ', ' '}},
        {{' ', ' ', ' '}},
    }};

    const inline static int field_size = 3;

    void draw_symbol(Vector2, char);
public:
    Field(const std::array<Texture2D, 3>& ts, Vector2 p, float s);

    void draw(std::array<std::array<Vector2, 3>, 3>&);

    bool add_to_field(std::pair<int, int>, char);

    FieldState check_field();

    void get_free_cells(std::vector<std::pair<int, int>>*);

    Vector2 get_position() { return position; }
};