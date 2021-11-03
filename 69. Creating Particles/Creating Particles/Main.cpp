#include"Screen.h"
#include"Particle.h"
#include"Swarm.h"
#undef main
using namespace Dust;

int main() {
	srand(time(NULL));

	Screen Visual_Interface;

	if (Visual_Interface.init() == false) {
		cout << "SDL init failed." << endl;
		SDL_Quit;
		return 1;
	}

	Swarm Starz;

	while (true) {
		//Update Particles
		//Draw Particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.002)) * 127.5;		//can also use cos or tan
		unsigned char green = (1 + sin(elapsed * 0.001)) * 127.5;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 127.5;

		const Particle* const ptrParticles = Starz.getParticle();

		for (int i = 0; i < Swarm::nParticles; i++) {
			Particle ptrfragments = ptrParticles[i];

			int x = (ptrfragments.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (ptrfragments.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			Visual_Interface.setPixel(x, y, red, green, blue);
		}

		//Draw Screen
		Visual_Interface.Update();

		//Check for messages/events
		if (Visual_Interface.processEvent() == false) {
			break;
		}
	}

	Visual_Interface.close();

	return 0;
}