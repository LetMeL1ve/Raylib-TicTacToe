#include <algorithm>
#include <array>
#include <raylib.h>


class GameLogic {
private:
    bool is_o_playing = true;
public:
    std::pair<int, int> get_player_move(const int, std::array<std::array<Vector2, 3>, 3>&);

    bool plays_o() { return is_o_playing; }
    void swap_players() {is_o_playing = !is_o_playing;}
};