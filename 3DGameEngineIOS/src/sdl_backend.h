#ifndef SDL_BACKEND_H
#define SDL_BACKEND_H

#include "SDL.h"

bool SDLGetIsCloseRequested();
void SDLSetIsCloseRequested(bool value);
SDL_Window* SDLCreateWindow(const char* title, int x, int y, int width, int height, bool fullscreen);
void SDLSetWindowFullscreen(bool value);
void SDLSwapBuffers();
void SDLDestroyWindow();
void SDLSetMousePosition(int x, int y);

#endif