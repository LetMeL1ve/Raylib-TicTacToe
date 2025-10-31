#include <raylib.h>

class Field {
private:
    Texture2D texture;
    Vector2 position;
    float scale;
public:
    Field(Texture2D& t, Vector2 p, float s) : texture(t), position(p), scale(s) {}

    void draw();
};