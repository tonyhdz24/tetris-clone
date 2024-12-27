#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Boolean value to determine whether to QUIT or not
  int quit = 0;

  SDL_Event event;
  // Parameter is a subsystem initialization flag
  // Initialize the SDL library
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  //   Creates window with specified position, demensions and optional flags
  SDL_Window *screen =
      SDL_CreateWindow("My First SDL Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

  // Check to make sure screen was created
  if (!screen) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  // Loop to keep screen up
  while (!quit) {
    // Wait for event
    SDL_WaitEvent(&event);

    // Even handling
    switch (event.type) {
    case SDL_QUIT:
      quit = 1;
      break;
    }
  }

  //   CleanUp and Quit SDL
  SDL_Quit();
  return 0;
}
