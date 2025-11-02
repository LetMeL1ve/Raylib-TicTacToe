#include <string>

namespace constants {
    // Relative path to the assets folder.
    inline const std::string main_assets_path = "../../../assets/";

    inline const std::string field_texture_path = main_assets_path + "field.png";
    inline const std::string x_texture_path = main_assets_path + "X.png";
    inline const std::string o_texture_path = main_assets_path + "O.png";

    // Global scale taht used for every object in game.
    const inline float global_scale = 4.0f;
    // Size of one symbol in pixels in scale "global_scale".
    const inline int symbol_size = 32 * global_scale;
    // GAp between symbols.
    const inline int gap = 4 * global_scale;
    // Size of field in scale "global_scale"
    const int field_size = 104 * global_scale;

}