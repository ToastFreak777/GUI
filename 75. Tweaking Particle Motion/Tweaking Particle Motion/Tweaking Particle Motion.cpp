#include"Swarm.h"
#undef main
using namespace Wave;

int main() {
	Screen Video;

	if (Video.init() == false) {
		cout << "SDL init failed." << endl;
		SDL_Quit();
		return 1;
	}

	Swarm Starz;

	double xCoords = Screen::SCREEN_WIDTH / 2;
	double yCoords = Screen::SCREEN_HEIGHT / 2;

	while (true) {
		//Draw Particles
		int elapsed = SDL_GetTicks();

		Starz.update(elapsed);

		unsigned char red = (1 + sin(elapsed * 0.002)) * 127.5;
		unsigned char green = (1 + (-sin(elapsed * 0.001))) * 127.5;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 127.5;

		const Particle* const ptrParticle = Starz.getParticle();

		for (int i = 0; i < Starz.NPARTICLES; i++) {
			Particle ptrfragment = ptrParticle[i];

			int x = (ptrfragment.m_x + 1) * xCoords;
			int y = ptrfragment.m_y * xCoords + yCoords;

			Video.setPixel(x, y, red, green, blue);
		}

		Video.boxBlur();

		//Draw Screen
		Video.update();

		//Check for messages/events
		if (Video.processEvent() == false) {
			break;
		}
	}

	Video.close();

	return 0;
}