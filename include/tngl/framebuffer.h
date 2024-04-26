#ifndef TNGL_FRAMEBUFFER_H_
#define TNGL_FRAMEBUFFER_H_
#include <glad/gl.h>
namespace tngl {
    struct Renderbuffer {
        Renderbuffer() { glCreateRenderbuffers(1, &_renderbuffer); }
        ~Renderbuffer() { glDeleteRenderbuffers(1, &_renderbuffer); }
        Renderbuffer(const Renderbuffer &) = delete;
        Renderbuffer operator=(const Renderbuffer &) = delete;
        Renderbuffer(Renderbuffer &&other) noexcept {
            _renderbuffer = other._renderbuffer;
            other._renderbuffer = 0;
        }
        Renderbuffer &operator=(Renderbuffer &&other) noexcept {
            _renderbuffer = other._renderbuffer;
            other._renderbuffer = 0;
            return *this;
        }
        operator GLuint() const { return _renderbuffer; }
        void storage(GLenum internalformat, GLsizei width, GLsizei height) const { glNamedRenderbufferStorage(_renderbuffer, internalformat, width, height); }
    private:
        GLuint _renderbuffer;
    };
    struct Framebuffer {
        Framebuffer() { glCreateFramebuffers(1, &_framebuffer); }
        ~Framebuffer() { glDeleteFramebuffers(1, &_framebuffer); }
        Framebuffer(const Framebuffer &) = delete;
        Framebuffer operator=(const Framebuffer &) = delete;
        Framebuffer(Framebuffer &&other) noexcept {
            _framebuffer = other._framebuffer;
            other._framebuffer = 0;
        }
        Framebuffer &operator=(Framebuffer &&other) noexcept {
            _framebuffer = other._framebuffer;
            other._framebuffer = 0;
            return *this;
        }
        operator GLuint() const { return _framebuffer; }
        void fb_texture(GLenum attachment, GLuint texture, GLint level) const {
            glNamedFramebufferTexture(_framebuffer, attachment, texture, level);
        }
        void fb_renderbuffer(GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) const {
            glNamedFramebufferRenderbuffer(_framebuffer, attachment, renderbuffertarget, renderbuffer);
        }
        void clearfi(GLenum buffer, GLint drawbuffer, const GLfloat depth, GLint stencil) const { glClearNamedFramebufferfi(_framebuffer, buffer, drawbuffer, depth, stencil); }
        void clearfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) const { glClearNamedFramebufferfv(_framebuffer, buffer, drawbuffer, value); }
        void cleariv(GLenum buffer, GLint drawbuffer, const GLint *value) const { glClearNamedFramebufferiv(_framebuffer, buffer, drawbuffer, value); }
        void clearuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) const { glClearNamedFramebufferuiv(_framebuffer, buffer, drawbuffer, value); }
    private:
        GLuint _framebuffer;
    };
}
#endif
