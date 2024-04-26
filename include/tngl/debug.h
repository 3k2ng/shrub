#ifndef TNGL_DEBUG_H_
#define TNGL_DEBUG_H_
#include <glad/gl.h>
#include <cstdio>
namespace tngl {
    void debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const *message, void const *user_param) {
        printf("[%s, %s, %s, %d] %s\n", [source]() {
		switch (source) {
                  case GL_DEBUG_SOURCE_API: return "API";
                  case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "WINDOW SYSTEM";
                  case GL_DEBUG_SOURCE_SHADER_COMPILER: return "SHADER COMPILER";
                  case GL_DEBUG_SOURCE_THIRD_PARTY: return "THIRD PARTY";
                  case GL_DEBUG_SOURCE_APPLICATION: return "APPLICATION";
                  case GL_DEBUG_SOURCE_OTHER: return "OTHER";
                  default: return "";
		} }(), [type]()  {
		switch (type) {
                  case GL_DEBUG_TYPE_ERROR: return "ERROR";
                  case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
                  case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
                  case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
                  case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
                  case GL_DEBUG_TYPE_MARKER: return "MARKER";
                  case GL_DEBUG_TYPE_OTHER: return "OTHER";
                  default: return "";
		} }(), [severity]() {
		switch (severity) {
                  case GL_DEBUG_SEVERITY_NOTIFICATION: return "NOTIFICATION";
                  case GL_DEBUG_SEVERITY_LOW: return "LOW";
                  case GL_DEBUG_SEVERITY_MEDIUM: return "MEDIUM";
                  case GL_DEBUG_SEVERITY_HIGH: return "HIGH";
                  default: return "";
		} }(), id, message);
    }
}
#endif
