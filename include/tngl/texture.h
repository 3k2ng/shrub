#pragma once
#include <glad/gl.h>
namespace tngl {
    struct Texture1D {
        Texture1D(GLsizei levels, GLenum internalformat, GLsizei width) {
            glCreateTextures(GL_TEXTURE_1D, 1, &_texture);
            glTextureStorage1D(_texture, levels, internalformat, width);
        }
        ~Texture1D() { glDeleteTextures(1, &_texture); }
        Texture1D(const Texture1D&) = delete;
        Texture1D operator=(const Texture1D&) = delete;
        Texture1D(Texture1D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
        }
        Texture1D& operator=(Texture1D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
            return *this;
        }
        operator GLuint() const { return _texture; }
        void subimage(GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) const {
            glTextureSubImage1D(_texture, level, xoffset, width, format, type, pixels);
        }
    private:
        GLuint _texture;
    };
    struct Texture2D {
        Texture2D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
            glCreateTextures(GL_TEXTURE_2D, 1, &_texture);
            glTextureStorage2D(_texture, levels, internalformat, width, height);
        }
        ~Texture2D() { glDeleteTextures(1, &_texture); }
        Texture2D(const Texture2D&) = delete;
        Texture2D operator=(const Texture2D&) = delete;
        Texture2D(Texture2D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
        }
        Texture2D& operator=(Texture2D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
            return *this;
        }
        operator GLuint() const { return _texture; }
        void subimage(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) const {
            glTextureSubImage2D(_texture, level, xoffset, yoffset, width, height, format, type, pixels);
        }
    private:
        GLuint _texture;
    };
    struct Texture3D {
        Texture3D(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
            glCreateTextures(GL_TEXTURE_3D, 1, &_texture);
            glTextureStorage3D(_texture, levels, internalformat, width, height, depth);
        }
        ~Texture3D() { glDeleteTextures(1, &_texture); }
        Texture3D(const Texture3D&) = delete;
        Texture3D operator=(const Texture3D&) = delete;
        Texture3D(Texture3D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
        }
        Texture3D& operator=(Texture3D&& other) noexcept {
            _texture = other._texture;
            other._texture = 0;
            return *this;
        }
        operator GLuint() const { return _texture; }
        void subimage(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) const {
            glTextureSubImage3D(_texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
        }
    private:
        GLuint _texture;
    };
}
