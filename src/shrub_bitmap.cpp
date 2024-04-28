#include "shrub/bitmap.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
namespace shrub {
    Bitmap Bitmap::from_file(const char *file_path) {
        int w, h, c;
        unsigned char* b;
        stbi_set_flip_vertically_on_load(true);
        b = stbi_load(file_path, &w, &h, &c, 0);
        return { w, h, c, b };
    }
    Bitmap::Bitmap(int w, int h, int c) : _width(w), _height(h), _comp(c), _bitmap(static_cast<unsigned char*>(malloc(w * h * c))) {}
    Bitmap::Bitmap(int w, int h, int c, unsigned char *b) : _width(w), _height(h), _comp(c), _bitmap(b) {}
    Bitmap::~Bitmap() {
        free(_bitmap);
    }
}
