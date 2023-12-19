#ifndef PLATFORM_H
#define PLATFORM_H
#include <GLUT/glut.h>
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <cstdint>

class Platform {
    friend class Imgui;

  public:
    Platform(char const *title, int windowWidth, int windowHeight,
             int textureWidth, int textureHeight);
    ~Platform();
    void Update(void const *buffer, int pitch);
    bool ProcessInput(uint8_t *keys);

  private:
    SDL_Window *window{};
    SDL_GLContext glContext{};
    GLuint framebuffer_texture;
    SDL_Renderer *renderer{};
    SDL_Texture *texture{};
};
#endif // !PLATFORM_H
