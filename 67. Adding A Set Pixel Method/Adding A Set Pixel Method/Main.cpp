#include"Screen.h"
#undef main
using namespace Dust;

int main(/*int argc, char* argv[]*/) {

	Screen Visual_Interface;
	if (Visual_Interface.init() == false) {
		cout << "Error initialzing SDL." << endl;
	}

	while (true) {
		// Update Particles
		
		// Draw Particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				Visual_Interface.setPixel(x, y, 128, 0, 255);
			}
		}

		Visual_Interface.setPixel(400, 300, 255, 255, 255);
		
		//Draw The Screen
		Visual_Interface.Update();
		// Check for messages/events
		if (Visual_Interface.processEvents() == false) {
			break;
		}
	}

	Visual_Interface.close();

	return 0;
}

/*

MAJOR DISCOVERY FOUND!!!
	I CAN EITHER USE THE METHOD FOUND IN MAIN()->int argc, char* argv[]

	OR I CAN UNDEFINE MAIN AND GET THE SAME RESULTS(FOR THIS PROGRAMS PURPOSES

	HERE IS SOME VALUABLE INFO ON THIS 

So if I undef main while using SDL, I don't work with standard library, just with something that is implemented in SDL? – Neomex Mar 5 '11 at 9:55

If someone tells you not to define main, it means "don't create a main function". The term define is not the same as #define, it means "create this function/variable" – Erik Mar 5 '11 at 9:58

On SDL, I don't use this, but I believe what it does is to use a #define to "rename" main. Your #undef would, in that case, cancel the renaming and SDL's own main would not be called. – Erik Mar 5 '11 at 10:01

*/