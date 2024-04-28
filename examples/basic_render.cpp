#include <shrub/window.h>
#include <glad/gl.h>
int main() {
	shrub::Window window(800, 600, "basic render");
	while (!window.should_close()) {
		glClearColor(0.2F, 0.4F, 0.3F, 1.0F);
		glClear(GL_COLOR_BUFFER_BIT);
		window.swap_buffers();
		window.poll_events();
	}
}
