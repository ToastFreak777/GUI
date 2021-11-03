#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* argv[]) {	// int argc, char* argv[]		I DONT KNOW WHY I NEED THIS!!!!!!!		its a command arguement

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	}

	// 1st arguement is the name of the window, 2nd/3rd arguement is the x/y position, 4th/5th arguement is the screen width and height
	SDL_Window* Window = SDL_CreateWindow(/*1*/"Particle Fire Explosion",
		/*2*/SDL_WINDOWPOS_UNDEFINED,/*3*/ SDL_WINDOWPOS_UNDEFINED,
		/*4*/SCREEN_WIDTH,/*5*/SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (Window == NULL) {
		SDL_Quit();
		return 2;
	}

	bool running = true;
	SDL_Event event;

	while (running) {
		//Update Particles//Draw Particles-//Check for Messages/Event
		while (SDL_PollEvent(&event)) {
			if (event.type==SDL_QUIT) {
				running = false;
			}
		}
	}


	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;
}