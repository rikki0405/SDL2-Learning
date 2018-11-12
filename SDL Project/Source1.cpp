// Standard Headers
/*
#include <SDL.h>
#include <stdio.h>

// Global Variables (ID-Carmack Formatting)
const int			SCREEN_WIDTH		=		640;			// Window width resolution
const int			SCREEN_HEIGHT		=		480;			// Window height resolution
SDL_Window*			gWindow				=		NULL;			// Render Window
SDL_Surface*		gScreenSurface		=		NULL;			// Window Surface
SDL_Surface*		gHelloWorld			=		NULL;			// Rendered Image

// Starts up SDL and creates a Window
bool init() {
	
	bool success = true;			// Initialization Flag

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Could Not Initialize! SDL Error: %s\n", SDL_GetError());
		!success;
	} else {
		
		// Create Window (TITLE, X-LOC, Y-LOC, X-SIZE, Y-SIZE, ARGU)
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL) {
			printf("Window  Could Not Be Created! SDL Error: %s\n", SDL_GetError());
			!success;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

// Loads Media
bool loadMedia() {

	bool success = true;			// Initialization Flag

	// Load Splash Image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");		// Should be located in Source Directory
	if (gHelloWorld == NULL) {
		printf("Splash Image Could Not Be Loaded! SDL Error: %s\n", SDL_GetError());
		!success;
	}
	return success;
}

// Frees up media and shuts down SDL
void close() {

	// Deallocate Surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	// Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL Subsystems
	SDL_Quit();
}

int main2(int argc, char* args[]) {

	// Start SDL and Create Window
	if (!init()) {
		printf("SDL Failed to Initialize!");
	} else {
		if (!loadMedia()) {
			printf("Failed to Load Media!");
		} else {
			
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);		// Apply the Image
			SDL_UpdateWindowSurface(gWindow);								// Update the Surface
			SDL_Delay(2000);												// 2-Second Delay
		}
	}
	close();		// Free Resources and Close SDL
	return 0;
}*/