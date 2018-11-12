/**/

// Starting Tutorial #4
#include <SDL.h>
#include <stdio.h>
#include <string>

// enumerators can go here if needed


// globals
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gCurrentSurface = NULL;	// buffer

bool init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Video INIT Failed");
		!success;
	}
	else {
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		//error check
		if (gWindow == NULL) {
			printf("gWindow Error");
		}
		else {
			// assign surface to window
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;

	// load media

	return success;
}

void close() {

	SDL_FreeSurface(gScreenSurface);
	SDL_FreeSurface(gCurrentSurface);
	gScreenSurface = NULL;
	gCurrentSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[]) {

	return 0;
}