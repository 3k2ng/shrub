#ifndef SHRUB_WINDOW_H_
#define SHRUB_WINDOW_H_
namespace shrub {
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
    private:
        void* _window;
    };
}
#endif
