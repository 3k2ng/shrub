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
        float cursor_x() const;
        float cursor_y() const;
        float cursor_delta_x() const;
        float cursor_delta_y() const;
        bool is_mouse_button_down(MouseButton button) const;
        bool is_mouse_button_repeated(MouseButton button) const;
        bool is_mouse_button_pressed(MouseButton button) const;
        bool is_mouse_button_released(MouseButton button) const;
        bool is_key_down(Key key) const;
        bool is_key_repeated(Key key) const;
        bool is_key_pressed(Key key) const;
        bool is_key_released(Key key) const;
    private:
        friend ___Callback;
        void* _window;
        float previous_cursor_x, previous_cursor_y;
        float current_cursor_x, current_cursor_y;
        bool previous_mouse_button_state[MAX_MOUSE_BUTTONS];
        bool current_mouse_button_state[MAX_MOUSE_BUTTONS];
        bool repeat_mouse_button_state[MAX_MOUSE_BUTTONS];
        bool previous_key_state[MAX_KEYS];
        bool current_key_state[MAX_KEYS];
        bool repeat_key_state[MAX_KEYS];
    };
}
#endif
