#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int quit = 0;
  SDL_Event event;
  // Initialize the SDL library
  // Parameter is a subsystem initialization flag
  SDL_Init(SDL_INIT_VIDEO);

  //   Creates window with specified position, demensions and optional flags
  SDL_Window *screen =
      SDL_CreateWindow("My First SDL Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  // Loop to keep screen up
  while (!quit) {
    SDL_WaitEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
      quit = 1;
      break;
    }
  }
  SDL_Quit();
  return 0;
}
