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
        void u1f(GLint location, GLfloat v0) const { glProgramUniform1f(_program, location, v0); }
        void u2f(GLint location, GLfloat v0, GLfloat v1) const { glProgramUniform2f(_program, location, v0, v1); }
        void u3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) const { glProgramUniform3f(_program, location, v0, v1, v2); }
        void u4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const { glProgramUniform4f(_program, location, v0, v1, v2, v3); }
        void u1i(GLint location, GLint v0) const { glProgramUniform1i(_program, location, v0); }
        void u2i(GLint location, GLint v0, GLint v1) const { glProgramUniform2i(_program, location, v0, v1); }
        void u3i(GLint location, GLint v0, GLint v1, GLint v2) const { glProgramUniform3i(_program, location, v0, v1, v2); }
        void u4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) const { glProgramUniform4i(_program, location, v0, v1, v2, v3); }
        void u1ui(GLuint location, GLuint v0) const { glProgramUniform1ui(_program, location, v0); }
        void u2ui(GLuint location, GLuint v0, GLuint v1) const { glProgramUniform2ui(_program, location, v0, v1); }
        void u3ui(GLuint location, GLuint v0, GLuint v1, GLuint v2) const { glProgramUniform3ui(_program, location, v0, v1, v2); }
        void u4ui(GLuint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) const { glProgramUniform4ui(_program, location, v0, v1, v2, v3); }
        void u1fv(GLint location, GLsizei count, const GLfloat *value) const { glProgramUniform1fv(_program, location, count, value); }
        void u2fv(GLint location, GLsizei count, const GLfloat *value) const { glProgramUniform2fv(_program, location, count, value); }
        void u3fv(GLint location, GLsizei count, const GLfloat *value) const { glProgramUniform3fv(_program, location, count, value); }
        void u4fv(GLint location, GLsizei count, const GLfloat *value) const { glProgramUniform4fv(_program, location, count, value); }
        void u1iv(GLint location, GLsizei count, const GLint *value) const { glProgramUniform1iv(_program, location, count, value); }
        void u2iv(GLint location, GLsizei count, const GLint *value) const { glProgramUniform2iv(_program, location, count, value); }
        void u3iv(GLint location, GLsizei count, const GLint *value) const { glProgramUniform3iv(_program, location, count, value); }
        void u4iv(GLint location, GLsizei count, const GLint *value) const { glProgramUniform4iv(_program, location, count, value); }
        void u1uiv(GLint location, GLsizei count, const GLuint *value) const { glProgramUniform1uiv(_program, location, count, value); }
        void u2uiv(GLint location, GLsizei count, const GLuint *value) const { glProgramUniform2uiv(_program, location, count, value); }
        void u3uiv(GLint location, GLsizei count, const GLuint *value) const { glProgramUniform3uiv(_program, location, count, value); }
        void u4uiv(GLint location, GLsizei count, const GLuint *value) const { glProgramUniform4uiv(_program, location, count, value); }
        void umat2fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix2fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat3fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix3fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat4fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix4fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat2x3fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix2x3fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat3x2fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix3x2fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat2x4fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix2x4fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat4x2fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix4x2fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat3x4fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix3x4fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
        void umat4x3fv(GLint location, GLsizei count, bool transpose, const GLfloat *value) const { glProgramUniformMatrix4x3fv(_program, location, count, transpose ? GL_TRUE : GL_FALSE, value); }
    private:
        GLuint _program;
    };
}
