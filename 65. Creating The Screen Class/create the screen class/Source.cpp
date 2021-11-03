#include"Screen.h"
using namespace Dust;

int main(int argc, char* argv[]) {

	Screen Visual_Interface;

	Visual_Interface.init();

	while (true) {
		// Update Particles// Draw Particles// Check for messages/events
		if (Visual_Interface.processEvents()==false) {
			break;
		}
	}

	Visual_Interface.close();

	return 0;
}