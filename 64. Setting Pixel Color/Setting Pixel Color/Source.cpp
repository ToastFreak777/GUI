#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* argv[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed." << endl;
		return 1;
	}

	SDL_Window* Window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* Render = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* Textures = SDL_CreateTexture(Render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	Uint32* Buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(Buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	//Buffer[30000] = 0xFFFFFFFF;		//Writing it using hexadecimal		each pair of F represents a value we are setting for the RGB or A

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		//Buffer[i] = 0xFFFFFFFF; //produces WHITE
		//Buffer[i] = 0xFF0000FF; //produces RED
		//Buffer[i] = 0x00FF00FF; //produces GREEN
		//Buffer[i] = 0x0000FFFF; //produces BLUE
		//Buffer[i] = 0xFFFF00FF; //produces YELLOW
		Buffer[i] = 0x00FF80FF;
	}

	SDL_UpdateTexture(Textures, NULL, Buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(Render);
	SDL_RenderCopy(Render, Textures, NULL, NULL);
	SDL_RenderPresent(Render);


	bool running = true;
	SDL_Event Events;
	while (running) {
		/*Updates Particles
			Draw Particles
				Check for Messages/Events*/
		while (SDL_PollEvent(&Events)) {
			if (Events.type == SDL_QUIT) {
				running = false;
			}
		}
	}

	if (Window == NULL) {
		SDL_Quit();
		return 2;
	}

	if (Render == NULL) {
		cout << "Couldn't create Renderer" << endl;
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return 3;
	}

	if (Textures == NULL) {
		cout << "Couldn't create Textures" << endl;
		SDL_DestroyRenderer(Render);
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return 4;
	}

	delete[] Buffer;
	SDL_DestroyRenderer(Render);
	SDL_DestroyTexture(Textures);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return 0;
}