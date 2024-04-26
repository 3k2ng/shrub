#ifndef SHRUB_BITMAP_H_
#define SHRUB_BITMAP_H_
namespace shrub {
    struct Bitmap {
        static Bitmap from_file(const char *file_path);
        Bitmap(int w, int h, int c);
        ~Bitmap();
        int width() const { return _width; }
        int height() const { return _height; }
        int comp() const { return _comp; }
        operator const unsigned char*() { return _bitmap; }
    private:
        Bitmap(int w, int h, int c, unsigned char *b);
        int _width, _height, _comp;
        unsigned char *_bitmap;
    };
}
#endif
