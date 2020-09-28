#include "Framebuffer.h"

int main() {
    Framebuffer* buffer = createFrameBuffer(10, 10);
    set(buffer, 0, 0, 'A');
    set(buffer, 1, 1, 'B');
    set(buffer, 2, 2, 'C');
    render(buffer);
}