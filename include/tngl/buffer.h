#ifndef TNGL_BUFFER_H_
#define TNGL_BUFFER_H_
#include <glad/gl.h>
namespace tngl {
    struct Buffer {
        Buffer() { glCreateBuffers(1, &buffer); }
        ~Buffer() { glDeleteBuffers(1, &buffer); }
        Buffer(const Buffer &) = delete;
        Buffer operator=(const Buffer &) = delete;
        Buffer(Buffer &&other) noexcept {
            buffer = other.buffer;
            other.buffer = 0;
        }
        Buffer &operator=(Buffer &&other) noexcept {
            buffer = other.buffer;
            other.buffer = 0;
            return *this;
        }
        operator GLuint() const { return buffer; }
        void storage(GLsizeiptr size, const void *data, GLbitfield flags) const { glNamedBufferStorage(buffer, size, data, flags); }
        void subdata(GLintptr offset, GLsizei size, const void *data) const { glNamedBufferSubData(buffer, offset, size, data); }
    private:
        GLuint buffer;
    };
    struct VertexArray {
        VertexArray() { glCreateVertexArrays(1, &_va); }
        ~VertexArray() { glDeleteVertexArrays(1, &_va); }
        VertexArray(const VertexArray &) = delete;
        VertexArray operator=(const VertexArray &) = delete;
        VertexArray(VertexArray &&other) noexcept {
            _va = other._va;
            other._va = 0;
        }
        VertexArray &operator=(VertexArray &&other) noexcept {
            _va = other._va;
            other._va = 0;
            return *this;
        }
        operator GLuint() const { return _va; }
        void vertex_buffer(GLuint binding_idx, const Buffer &buffer, GLintptr offset, GLsizei stride) const {
            glVertexArrayVertexBuffer(_va, binding_idx, buffer, offset, stride);
        }
        void element_buffer(const Buffer &buffer) const { glVertexArrayElementBuffer(_va, buffer); }
        void enable_attrib(GLuint idx) const { glEnableVertexArrayAttrib(_va, idx); }
        void disable_attrib(GLuint idx) const { glDisableVertexArrayAttrib(_va, idx); }
        void attrib_format(GLuint attrib_idx, GLint size, GLenum type, bool normalized, GLuint relative_offset) const {
            glVertexArrayAttribFormat(_va, attrib_idx, size, type, normalized ? GL_TRUE : GL_FALSE, relative_offset);
        }
        void attrib_binding(GLuint attrib_idx, GLuint binding_idx) const { glVertexArrayAttribBinding(_va, attrib_idx, binding_idx); }

    private:
        GLuint _va;
    };
}
#endif
