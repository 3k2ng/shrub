#include <shrub/context.h>
#include <shrub/window.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

int main() {
	shrub::Window window(800, 600, "basic render");
	window.make_current();
	shrub::Context::load_gl();
	while (!window.should_close()) {
		glClearColor(0.2F, 0.4F, 0.3F, 1.0F);
		glClear(GL_COLOR_BUFFER_BIT);
		window.swap_buffers();
		window.poll_events();
	}
}
