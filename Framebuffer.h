#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

typedef struct Framebuffer Framebuffer;

Framebuffer* createFrameBuffer(int width, int height);
void destroyFrameBuffer(Framebuffer *buffer);
void render(Framebuffer *buffer);
void fill(Framebuffer *buffer, char sign);
void set(Framebuffer *buffer, int x, int y, char sign);

#endif