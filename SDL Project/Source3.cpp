/*
// This time, let's try and initialize everything from memory
#include <SDL.h>
#include <stdio.h>
#include <string>

// Enumerations
enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

// Declarations
const int			SCREEN_WIDTH		=		640;					// Screen Width
const int			SCREEN_HEIGHT		=		480;					// Screen Height
SDL_Window*			gWindow				=		NULL;					// The window instance
SDL_Surface*		gScreenSurface		=		NULL;					// Surface of the window
SDL_Surface*		gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];			// The images that will respond to a key press
SDL_Surface*		gCurrentSurface		=		NULL;					// Current Default Surface



// Functions
SDL_Surface* loadSurface(std::string path) {

	// Load Image at Specified Path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

	// Error Check
	if (loadedSurface == NULL) {
		printf("Error Loading: %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}

	return loadedSurface;
}

bool init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Video Init Error: %s\n", SDL_GetError());
		!success;
	}
	else {
		gWindow = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		printf("Init Success\n");
		// Error Check
		if (gWindow == NULL) {
			printf("Window Init Error: %s\n", SDL_GetError());
			!success;
		}
		else {
			// Forgot this twice... now its fixed
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;

	// Load media - Enumerated Images
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("press.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL) {
		printf("Failed to load Default Image!");
		!success;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL) {
		printf("Failed to load Up Image!");
		!success;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
		printf("Failed to load Down Image!");
		!success;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
		printf("Failed to load Left Image!");
		!success;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL) {
		printf("Failed to load Right Image!");
		!success;
	}
	printf("LoadMedia Success\n");
	return success;
}

void close() {

	// Free Surfaces
	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = NULL;

	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = NULL;

	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = NULL;

	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = NULL;

	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = NULL;

	SDL_FreeSurface(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT]);
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = NULL;
	
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[]) {

	
	if (init()) {
		if (loadMedia()) {

			bool quit = false;
			SDL_Event e;
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			while (!quit) {

				while (SDL_PollEvent(&e) != 0) {

					if (e.type == SDL_QUIT) {
						quit = true;
					}

					else if (e.type = SDL_KEYDOWN) {
						switch (e.key.keysym.sym) {
						case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							printf("UP Pressed\n");
							break;
						case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							printf("DOWN Pressed\n");
							break;
						case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							printf("LEFT Pressed\n");
							break;
						case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							printf("RIGHT Pressed\n");
							break;
						default:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					}
				}

				// Update the Surface Draw
				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);

			}
		}
		else
		{
			printf("LoadMedia Failed"); \
		}
	}
	else {
		printf("Init Failed");
	}

	return 0;
}*/