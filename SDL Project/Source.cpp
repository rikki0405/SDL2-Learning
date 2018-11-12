// My First SDL2 Program
// Goal: Opening a Window and Displaying Something
// Rikki Jones - 07/11/2018

#include <SDL.h>							//	STL Library
#include <stdio.h>							// Basic I/O for Console Output

const int SCREEN_WIDTH = 640;				// Constant Screen Width
const int SCREEN_HEIGHT = 480;				// Constant Screen Height

int main1(int argc, char* args[]) {

	SDL_Window* window = NULL;				// The window we will render to

	SDL_Surface* screenSurface = NULL;		// The surface contained by the window


	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (window == NULL) {
			printf("Window could not be created. SDLError: %s\n", SDL_GetError());
		}
		else {

			// Get the window surface
			screenSurface = SDL_GetWindowSurface(window);

			// Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			// Update the surface
			SDL_UpdateWindowSurface(window);

			// Wait 2 seconds
			SDL_Delay(2000);
		}
	}

	// Destroy Window
	SDL_DestroyWindow(window);

	// Quit SDL Sub-Systems
	SDL_Quit();

	return 0;
}