#include "shrub/window.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
namespace shrub {
    struct ___GlfwInit {
        ___GlfwInit() { glfwInit(); }
        ~___GlfwInit() { glfwTerminate(); }
    };
    struct ___Callback {
        static void _cursor_pos_callback(GLFWwindow *window_handle, double xpos, double ypos) {
            Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
            window_ptr->_input.current_cursor_x = static_cast<float>(xpos);
            window_ptr->_input.current_cursor_y = static_cast<float>(ypos);
        }
        static void _mouse_button_callback(GLFWwindow *window_handle, int button, int action, int mods) {
            Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
            if (action == GLFW_RELEASE) window_ptr->_input.current_mouse_button_state[button] = false;
            else if (action == GLFW_PRESS) window_ptr->_input.current_mouse_button_state[button] = true;
            else if (action == GLFW_REPEAT) window_ptr->_input.repeat_mouse_button_state[button] = true;
        }
        static void _key_callback(GLFWwindow *window_handle, int key, int scancode, int action, int mods) {
            Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
            if (action == GLFW_RELEASE) window_ptr->_input.current_key_state[key] = false;
            else if (action == GLFW_PRESS) window_ptr->_input.current_key_state[key] = true;
            else if (action == GLFW_REPEAT) window_ptr->_input.repeat_key_state[key] = true;
        }
    };
    Window::Window(int width, int height, const char* title) {
        static ___GlfwInit glfw_init;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwSetWindowUserPointer(static_cast<GLFWwindow*>(_window), this);
        glfwSetCursorPosCallback(static_cast<GLFWwindow*>(_window), ___Callback::_cursor_pos_callback);
        glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(_window), ___Callback::_mouse_button_callback);
        glfwSetKeyCallback(static_cast<GLFWwindow*>(_window), ___Callback::_key_callback);
        glfwMakeContextCurrent(static_cast<GLFWwindow*>(_window));
        gladLoadGL(glfwGetProcAddress);
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
    void Window::poll_events() {
        _input.previous_cursor_x = _input.current_cursor_x;
        _input.previous_cursor_y = _input.current_cursor_y;
        for (int i = 0; i < MAX_KEY; ++i) {
            _input.previous_key_state[i] = _input.current_key_state[i];
            _input.repeat_key_state[i] = false;
        }
        for (int i = 0; i < MAX_MOUSE_BUTTON; ++i) {
            _input.previous_mouse_button_state[i] = _input.current_mouse_button_state[i];
            _input.repeat_mouse_button_state[i] = false;
        }
        glfwPollEvents();
    }
}
