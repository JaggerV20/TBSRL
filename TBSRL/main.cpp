#include "main.h"

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

//I don't have an image or directory, so this won't work
bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
    if (gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    return loadedSurface;
}

int main(int argc, char* args[]) {

    bool quit = false;
    SDL_Event e;

    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        }
    }

    //Update the surface
    SDL_UpdateWindowSurface(gWindow);

    while (!quit) {

        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    
    }

    close();

    return 0;
}
