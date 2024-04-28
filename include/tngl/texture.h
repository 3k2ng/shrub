#pragma once
#include <glad/gl.h>
namespace tngl {
    struct Texture {
        Texture(GLenum target) { glCreateTextures(target, 1, &_texture); }
        ~Texture() { glDeleteTextures(1, &_texture); }
        Texture(const Texture&) = delete;
        Texture operator=(const Texture&) = delete;
        Texture(Texture&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
        }
        Texture& operator=(Texture&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
            return *this;
        }
        operator GLuint() const { return _texture; }
    private:
        GLuint _texture;
    };
}
