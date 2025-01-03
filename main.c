#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  // Boolean value to determine whether to QUIT or not
  int quit = 0;

  SDL_Event event;

  // SpaceShip position
  int x = 288;
  int y = 288;
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
  // Creates an instance of SDL_Renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, 0);

  // Img we want to render
  SDL_Surface *image = SDL_LoadBMP("spaceship.bmp");
  // Image error handling
  if (!image) {
    printf("Failed to load image: %s\n", SDL_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 1;
  }
  // Initialize texture used to render image
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
  // texture error handling
  if (!texture) {
    printf("Failed to create texture: %s\n", SDL_GetError());
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 1;
  }
  // Free an RGB surface
  SDL_FreeSurface(image);

  // Set the color used for drawing operations
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Check to make sure screen was created
  if (!screen) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  // Loop to keep screen up
  while (!quit) {
    // Wait for event
    SDL_PollEvent(&event);

    // Even handling
    switch (event.type) {
    // handle keydown event
    case SDL_KEYDOWN:
      // Handle select keydowns
      switch (event.key.keysym.sym) {
      case SDLK_LEFT:
        x--;
        break;
      case SDLK_RIGHT:
        x++;
        break;
      case SDLK_UP:
        y--;
        break;
      case SDLK_DOWN:
        y++;
        break;
      }
      break;
    case SDL_QUIT:
      quit = 1;
      break;
    }

    // Rendering the Image
    // SDL_RenderCopy copies the texture to the output device
    // SDL_RenderPresent commits the texture to the vidoe memory displaying
    // image

    // Image display settings
    SDL_Rect dstrect = {x, y, 64, 64};
    // Clear the current rendering target with the drawing color (Make the whole
    // background white)
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
  }

  //   CleanUp and Quit SDL

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(screen);
  SDL_Quit();
  return 0;
}
