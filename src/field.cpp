#include "field.h"

void Field::draw() {
    // Getting texture size
    const int size = this->texture.width;

    // Creating rectangels for DrawTexturePro fucntion.
    Rectangle source = {0, 0, size, size};
    Rectangle dest = {position.x, position.y, size * scale, size * scale};
    
    DrawTexturePro(this->texture, source, dest, Vector2 {0, 0}, 0.0f, WHITE);
}