#include "shrub/window.h"
#include "shrub/context.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
namespace shrub {
    Window::Window(int width, int height, const char* title) {
        Context::instance();
        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    }
    Window::~Window() {
        glfwDestroyWindow(static_cast<GLFWwindow*>(_window));
    }
    Window::Window(Window &&other) noexcept {
        _window = other._window;
        other._window = nullptr;
    }
    Window& Window::operator=(Window &&other) noexcept {
        _window = other._window;
        other._window = nullptr;
        return *this;
    }
    bool Window::should_close() const {
        return glfwWindowShouldClose(static_cast<GLFWwindow*>(_window));
    }
    void Window::swap_buffers() const {
        glfwSwapBuffers(static_cast<GLFWwindow*>(_window));
    }
    void Window::make_current() const {
        glfwMakeContextCurrent(static_cast<GLFWwindow*>(_window));
    }
}
