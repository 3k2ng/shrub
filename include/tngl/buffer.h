#pragma once
#include <glad/gl.h>
namespace tngl {
    struct Buffer {
        Buffer(GLsizeiptr size, const void *data, GLbitfield flags) {
            glCreateBuffers(1, &buffer);
            glNamedBufferStorage(buffer, size, data, flags);
        }
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
    private:
        GLuint _va;
    };
}
