#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* argv[]) {	// int argc, char* argv[]		I DONT KNOW WHY I NEED THIS!!!!!!!		its a command arguement

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	}

	cout << "SDL Init succeeded" << endl;

	SDL_Quit();

	return 0;
}