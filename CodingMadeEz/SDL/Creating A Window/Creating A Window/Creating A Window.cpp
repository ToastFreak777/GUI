#include"Screen.h"

int main(int argc, char* argv[]){
	Screen Window;

	if (Window.init() < 0) {
		cout << "SDL init failed\n";
		SDL_GetError();
		SDL_Quit();
		return 1;
	}

	return 0;
}