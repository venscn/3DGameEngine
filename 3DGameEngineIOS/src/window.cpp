#include "window.h"
#include "SDL.h"
#include "sdl_backend.h"
#include "OpenGL.h"

int Window::s_width = 0;
int Window::s_height = 0;
std::string Window::s_title = "Title";

SDL_Window* Window::Create(int width, int height, const std::string& title)
{
	Window::s_width = width;
	Window::s_height = height;
	Window::s_title = title;

	SDL_Init(SDL_INIT_EVERYTHING);
    
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

	return SDLCreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, true);
}

void Window::Render()
{
	SDLSwapBuffers();
}

void Window::Dispose()
{
	SDLDestroyWindow();
	SDL_Quit();
}

bool Window::IsCloseRequested()
{
	return SDLGetIsCloseRequested();
}

void Window::SetFullScreen(bool value)
{
	SDLSetWindowFullscreen(value);
}

int Window::GetWidth()
{
	return s_width;
}

int Window::GetHeight()
{
	return s_height;
}

float Window::GetAspect()
{
	return (float)GetWidth()/(float)GetHeight();
}

const std::string& Window::GetTitle()
{
	return s_title;
}