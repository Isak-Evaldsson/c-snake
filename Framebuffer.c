#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Framebuffer.h"

struct Framebuffer
{
    char *buffer;
    char *z;
    int width;
    int height;
};

Framebuffer* createFrameBuffer(int width, int height) {
    Framebuffer* buffer = (Framebuffer*) malloc(sizeof(Framebuffer));
    int size = width * height;

    buffer->z = (char*) malloc(size * sizeof(char));
    buffer->buffer = (char*) malloc(size * sizeof(char));
    buffer->width = width;
    buffer->height = height;
    
    memset(buffer->buffer, 32, size);

    return buffer;
}

int size(Framebuffer* buffer) {
    return buffer->width * buffer->height;
}

void fill(Framebuffer *buffer, char sign) {
    memset(buffer->buffer, sign, size(buffer));
}

void set(Framebuffer *buffer, int x, int y, char sign) {
    if (x >= 0 && x < buffer->width && y >= 0 && y < buffer->height){
        buffer->buffer[y * buffer->width + x] = sign;
    }
}

void destroyFrameBuffer(Framebuffer *buffer) {
    free(buffer->buffer);
    free(buffer->z);
    free(buffer);
}

void render(Framebuffer *buffer) {
    printf("\x1b[H");
    for (int i = 0; i < buffer->width * buffer->height; i++) {
        if (i % buffer->width == 0){
            putchar(10);
        }
        putchar(buffer->buffer[i]);
    }
}