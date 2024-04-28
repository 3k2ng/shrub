#pragma once
#include <glad/gl.h>
namespace tngl {
    struct Shader {
        Shader(GLenum type) { _shader = glCreateShader(type); }
        ~Shader() { glDeleteShader(_shader); }
        Shader(const Shader&) = delete;
        Shader operator=(const Shader&) = delete;
        Shader(Shader &&other) noexcept {
            _shader = other._shader;
            other._shader = 0;
        }
        Shader &operator=(Shader &&other) noexcept {
            _shader = other._shader;
            other._shader = 0;
            return *this;
        }
        operator GLuint() const { return _shader; }
        void source(const char *shader_source) const {
            glShaderSource(_shader, 1, &shader_source, nullptr);
            glCompileShader(_shader);
        }
    private:
        GLuint _shader;
    };
    struct Program {
        Program() { _program = glCreateProgram(); }
        ~Program() { glDeleteProgram(_program); }
        Program(const Program &) = delete;
        Program operator=(const Program &) = delete;
        Program(Program &&other) noexcept {
            _program = other._program;
            other._program = 0;
        }
        Program &operator=(Program &&other) noexcept {
            _program = other._program;
            other._program = 0;
            return *this;
        }
        operator GLuint() const { return _program; }
        void attach(const Shader& shader) const { glAttachShader(_program, shader); }
        void link() const { glLinkProgram(_program); }
    private:
        GLuint _program;
    };
}
