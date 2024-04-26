#include "shrub/context.h"
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
namespace shrub {
    const Context& Context::instance() {
        static Context instance;
        return instance;
    }
    Context::Context() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    Context::~Context() {
        glfwTerminate();
    }
    void Context::poll_events() {
        glfwPollEvents();
    }
    void Context::load_gl() {
        gladLoadGL(glfwGetProcAddress);
    }
}