#include <SDL.h>
#include <stdio.h>
#include <iostream>


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720; 

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_ENTER,
    KEY_PRESS_SURFACE_TOTAL
};

//Later include a function to set these using key inputs
SDL_Keycode CTRL_UP = SDLK_w;
SDL_Keycode CTRL_DOWN = SDLK_s;
SDL_Keycode CTRL_LEFT = SDLK_a;
SDL_Keycode CTRL_RIGHT = SDLK_d;
SDL_Keycode CTRL_ENTER = SDLK_RETURN;

int xChange = 0;
int yChange = 0;
