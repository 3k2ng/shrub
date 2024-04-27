#pragma once
namespace shrub {
    struct Context {
        static const Context &instance();
        Context(const Context &) = delete;
        Context operator=(const Context &) = delete;
        static void load_gl();
    private:
        Context();
        ~Context();
    };
}
