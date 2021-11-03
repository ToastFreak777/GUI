#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* argv[]) {

	const int SCREENWIDTH = 800;
	const int SCREENHEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	}

	SDL_Window* Window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);

	if (Window == NULL) {
		SDL_Quit();
		return 2;
	}

	//Where the program will render or write out information too
	SDL_Renderer* Render = SDL_CreateRenderer(Window,-1,SDL_RENDERER_PRESENTVSYNC);
	// SDL_PIXELFORMAT_RGBA8888-> how many bits you want a single pixel to represent// SDL_TEXTUREACCESS_STATIC->has to do with the way we are writing to texture
	SDL_Texture* Textures = SDL_CreateTexture(Render,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,SCREENWIDTH,SCREENHEIGHT);

	if (Render == NULL) {
		cout << "Couldn't create Renderer" << endl;
		SDL_DestroyWindow(Window); // at this point you already created a window so you have to destroy it before closing the program
		SDL_Quit();
		return 3;
	}

	if (Textures == NULL) {
		cout << "Couldn't create Textures" << endl;
		SDL_DestroyRenderer(Render); // at this point you already created a Render so you have to destroy it before closing the program
		SDL_DestroyWindow(Window); // at this point you already created a window so you have to destroy it before closing the program
		SDL_Quit();
		return 4;
	}

	//type declared by SDL equivalent to an int
	Uint32* Buffer = new Uint32[SCREENWIDTH * SCREENHEIGHT]; //Allocating memory for the pixels

	memset(Buffer, 255, SCREENWIDTH * SCREENHEIGHT * sizeof(Uint32));	//255 will give us white background color (0xFF is equal to 255)(0xFF is a hexadecimal value)

	SDL_UpdateTexture(Textures, NULL, Buffer, SCREENWIDTH * sizeof(Uint32));
	SDL_RenderClear(Render);
	SDL_RenderCopy(Render, Textures, NULL, NULL);
	SDL_RenderPresent(Render);

	bool running = true;
	SDL_Event Events;

	while (running) {
		/*
		Update Particles
		Draw Particles
		Check for messages/events */
		while (SDL_PollEvent(&Events)) {
			if (Events.type == SDL_QUIT) {
				running = false;
			}
		}
	}

	delete[] Buffer;
	SDL_DestroyRenderer(Render);
	SDL_DestroyTexture(Textures);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;
}

/*
this could be revised and simplified so that there is no duplicate code but since this is my first time its fine.
*/