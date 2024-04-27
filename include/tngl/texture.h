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
        void parameterIiv(GLenum pname, const GLint* params) const { glTextureParameterIiv(_texture, pname, params); }
        void parameterIuiv(GLenum pname, const GLuint* params) const { glTextureParameterIuiv(_texture, pname, params); }
        void parameterf(GLenum pname, GLfloat param) const { glTextureParameterf(_texture, pname, param); }
        void parameterfv(GLenum pname, const GLfloat* param) const { glTextureParameterfv(_texture, pname, param); }
        void parameteri(GLenum pname, GLint param) const { glTextureParameteri(_texture, pname, param); }
        void parameteriv(GLenum pname, const GLint* param) const { glTextureParameteriv(_texture, pname, param); }
        void storage1d(GLsizei levels, GLenum internalformat, GLsizei width) const { 
            glTextureStorage1D(_texture, levels, internalformat, width); 
        }
        void storage2d(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) const { 
            glTextureStorage2D(_texture, levels, internalformat, width, height); 
        }
        void storage3d(GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) const { 
            glTextureStorage3D(_texture, levels, internalformat, width, height, depth); 
        }
        void subimage1d(GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) const { 
            glTextureSubImage1D(_texture, level, xoffset, width, format, type, pixels);
        }
        void subimage2d(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) const { 
            glTextureSubImage2D(_texture, level, xoffset, yoffset, width, height, format, type, pixels);
        }
        void subimage3d(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) const { 
            glTextureSubImage3D(_texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
        }
        void generate_mipmap() const { glGenerateTextureMipmap(_texture); }
    private:
        GLuint _texture;
    };
}
