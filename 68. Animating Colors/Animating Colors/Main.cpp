#include"Screen.h"

using namespace Dust;

int main(int argc, char* argv[]) {
	Screen Visual_Interface;

	if (Visual_Interface.init() == false) {
		cout << "SDL init failed." << endl;
	}

	while (true) {
		//Update Paricles
		int Elapsed = SDL_GetTicks();
		unsigned char green = (1 + sin(Elapsed*0.001))*127.5;	//could also use cos and tan
		unsigned char red = (1 + sin(Elapsed * 0.002)) * 127.5;
		unsigned char blue = (1 + sin(Elapsed * 0.003)) * 127.5;


		//Draw Particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				Visual_Interface.setPixel(x, y, red, green, blue); //Screen fill color code
			}
		}

		//Visual_Interface.setPixel(400, 300, 255, 255, 255); Center pixel dot

		//Check for messages/Events
		Visual_Interface.Update();
		if (Visual_Interface.processEvents() == false) {
			break;
		}
	}

	Visual_Interface.close();

	return 0;
}