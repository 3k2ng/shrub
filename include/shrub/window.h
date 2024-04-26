#ifndef SHRUB_WINDOW_H_
#define SHRUB_WINDOW_H_
#include "shrub/input.h"
namespace shrub {
    struct ___Callback;
    struct Window {
        Window(int width, int height, const char* title);
        ~Window();
        Window(const Window &) = delete;
        Window operator=(const Window &) = delete;
        Window(Window &&other) noexcept;
        Window &operator=(Window &&other) noexcept;
        void* handle() const { return _window; }
        bool should_close() const;
        void swap_buffers() const;
        void make_current() const;
        void poll_events();
        float cursor_x() const { return _input.current_cursor_x; }
        float cursor_y() const { return _input.current_cursor_y; }
        float cursor_delta_x() const { return _input.current_cursor_x - _input.previous_cursor_x; };
        float cursor_delta_y() const { return _input.current_cursor_y - _input.previous_cursor_y; };
        bool is_mouse_button_down(MouseButton button) const { return _input.current_mouse_button_state[static_cast<int>(button)]; }
        bool is_mouse_button_repeated(MouseButton button) const { return _input.repeat_mouse_button_state[static_cast<int>(button)]; }
        bool is_mouse_button_pressed(MouseButton button) const { return !_input.previous_mouse_button_state[static_cast<int>(button)] && _input.current_mouse_button_state[static_cast<int>(button)]; }
        bool is_mouse_button_released(MouseButton button) const { return _input.previous_mouse_button_state[static_cast<int>(button)] && !_input.current_mouse_button_state[static_cast<int>(button)]; }
        bool is_key_down(Key key) const { return _input.current_key_state[static_cast<int>(key)]; }
        bool is_key_repeated(Key key) const { return _input.repeat_key_state[static_cast<int>(key)]; }
        bool is_key_pressed(Key key) const { return !_input.previous_key_state[static_cast<int>(key)] && _input.current_key_state[static_cast<int>(key)]; }
        bool is_key_released(Key key) const { return _input.previous_key_state[static_cast<int>(key)] && !_input.current_key_state[static_cast<int>(key)]; }
    private:
        friend ___Callback;
        void* _window;
        Input _input;
    };
}
#endif
