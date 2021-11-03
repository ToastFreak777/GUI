#include "Screen.h"

Screen::Screen() :mWindow(nullptr) {

}
Screen::~Screen() {

}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	else {
		mWindow = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN);
		if (mWindow < 0) {
			return false;
		}

		else {
			SDL_UpdateWindowSurface(mWindow); //when we create the window nothing actually happens we have to call this function to make a screen appear and update it.
			SDL_Delay(2000); // this pauses the execution of the program for how long we input (2000 = 2 seconds)
		}
	}

	SDL_DestroyWindow(mWindow);
	SDL_Quit();

	return true;
}

/*
the reason for the SDL_Delay is because unlike with caveofprogramming in the int main function we are not using a loop for continously updating the screen
	with the lack of a loop the program will close immediately after running 
		that is the purpose of the delay-> it pauses the program(Milliseconds) (2000ms->2s)
*/