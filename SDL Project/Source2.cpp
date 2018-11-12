/*

#include <SDL.h>
#include <stdio.h>
#include <string>

// Global Variables
const int			SCREEN_WIDTH		=		640;		// Screen Width Resolution
const int			SCREEN_HEIGHT		=		480;		// Screen Height Resolution
const std::string   BMP_FILENAME		=		"x.bmp";	// BMP Filename
SDL_Window*			gWindow				=		NULL;		// SDL Window
SDL_Surface*		gScreenSurface		=		NULL;		// Surface for Window
SDL_Surface*		gBMP				=		NULL;		// Sample Image


bool init() {
	bool success = true;

	// Initialize Window
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Failed to Initialize Window! SDL Error: %s\n", SDL_GetError());
		!success;
	}
	else {
		gWindow = SDL_CreateWindow("SDL Window Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		// Check if window was properly created
		if (gWindow == NULL) {
			printf("Window Creation Failed! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {

	bool success = true;

	// load media
	gBMP = SDL_LoadBMP(BMP_FILENAME.c_str());	// *.c_str() - Convert std::string to char

	if (gBMP == NULL) {
		printf("Load Media Failed. SDL Error; %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void close() {

	// Deallocate Surface
	SDL_FreeSurface(gBMP);
	gBMP = NULL;

	// Destory Window
	SDL_DestroyWindow(gWindow);

	// Quit SDL Subsystems
	SDL_Quit();
}

int main2(int argc, char* args[]) {

	if (!init()) {
		printf("SDL Initialization Unsuccessful.");
	}
	else {
		if (!loadMedia) {
			printf("SDL Loading Media Unsuccessful.");
		}
		else {

			bool quit = false;		// Run Loop While FALSE
			SDL_Event e;			// Event Handler

			while (!quit) {

				// Handle Events on Queue
				while (SDL_PollEvent(&e) != 0) {

					// User Requests Quit
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}

				// Draw and Update Surface
				SDL_BlitSurface(gBMP, NULL, gScreenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	return 0;
}*/