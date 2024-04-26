#include "shrub/window.h"
#include "shrub/context.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
namespace shrub {
    static void _cursor_pos_callback(GLFWwindow *window_handle, double xpos, double ypos) {
        Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
        window_ptr->current_cursor_x = static_cast<float>(xpos);
        window_ptr->current_cursor_y = static_cast<float>(ypos);
    }
    static void _mouse_button_callback(GLFWwindow *window_handle, int button, int action, int mods) {
        Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
        if (action == GLFW_RELEASE) window_ptr->current_mouse_button_state[button] = false;
        else if (action == GLFW_PRESS) window_ptr->current_mouse_button_state[button] = true;
        else if (action == GLFW_REPEAT) window_ptr->repeat_mouse_button_state[button] = true;
    }
    static void _key_callback(GLFWwindow *window_handle, int key, int scancode, int action, int mods) {
        Window* window_ptr = static_cast<Window*>(glfwGetWindowUserPointer(window_handle));
        if (action == GLFW_RELEASE) window_ptr->current_key_state[key] = false;
        else if (action == GLFW_PRESS) window_ptr->current_key_state[key] = true;
        else if (action == GLFW_REPEAT) window_ptr->repeat_key_state[key] = true;
    }
    Window::Window(int width, int height, const char* title) {
        Context::instance();
        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwSetWindowUserPointer(static_cast<GLFWwindow*>(_window), this);
        glfwSetCursorPosCallback(static_cast<GLFWwindow*>(_window), _cursor_pos_callback);
        glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(_window), _mouse_button_callback);
        glfwSetKeyCallback(static_cast<GLFWwindow*>(_window), _key_callback);
        previous_cursor_x = 0.F; previous_cursor_y = 0.F;
        current_cursor_x = 0.F; current_cursor_y = 0.F;
        for (int i = 0; i < MAX_MOUSE_BUTTONS; ++i) {
            previous_mouse_button_state[i] = false;
            current_mouse_button_state[i] = false;
            repeat_mouse_button_state[i] = false;
        }
        for (int i = 0; i < MAX_KEYS; ++i) {
            previous_key_state[i] = false;
            current_key_state[i] = false;
            repeat_key_state[i] = false;
        }
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
        previous_cursor_x = current_cursor_x;
        previous_cursor_y = current_cursor_y;
        for (int i = 0; i < MAX_KEYS; ++i) {
            previous_key_state[i] = current_key_state[i];
            repeat_key_state[i] = false;
        }
        for (int i = 0; i < MAX_MOUSE_BUTTONS; ++i) {
            previous_mouse_button_state[i] = current_mouse_button_state[i];
            repeat_mouse_button_state[i] = false;
        }
        glfwPollEvents();
    }
    float Window::cursor_x() const { return current_cursor_x; };
    float Window::cursor_y() const { return current_cursor_y; };
    float Window::cursor_delta_x() const { return current_cursor_x - previous_cursor_x; };
    float Window::cursor_delta_y() const { return current_cursor_y - previous_cursor_y; };
    bool Window::is_mouse_button_down(MouseButton button) const { return current_mouse_button_state[static_cast<int>(button)]; }
    bool Window::is_mouse_button_repeated(MouseButton button) const { return repeat_mouse_button_state[static_cast<int>(button)]; }
    bool Window::is_mouse_button_pressed(MouseButton button) const { return !previous_mouse_button_state[static_cast<int>(button)] && current_mouse_button_state[static_cast<int>(button)]; }
    bool Window::is_mouse_button_released(MouseButton button) const { return previous_mouse_button_state[static_cast<int>(button)] && !current_mouse_button_state[static_cast<int>(button)]; }
    bool Window::is_key_down(Key key) const { return current_key_state[static_cast<int>(key)]; }
    bool Window::is_key_repeated(Key key) const { return repeat_key_state[static_cast<int>(key)]; }
    bool Window::is_key_pressed(Key key) const { return !previous_key_state[static_cast<int>(key)] && current_key_state[static_cast<int>(key)]; }
    bool Window::is_key_released(Key key) const { return previous_key_state[static_cast<int>(key)] && !current_key_state[static_cast<int>(key)]; }
}
