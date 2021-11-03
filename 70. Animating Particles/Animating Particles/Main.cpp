#include"Screen.h"
#include"Particle.h"
#include"Swarm.h"
#undef main
using namespace Dust;

int main() {
	srand(time(NULL));

	Screen video;

	if (video.init() == false) {
		cout << "SDL init failed" << endl;
		SDL_Quit;
		return 1;
	}
	Swarm Starz;

	while (true) {
		//Draw Particles

		int elapsed = SDL_GetTicks();

		video.clear();
		Starz.Update();

		unsigned char red = (1 + sin(elapsed * 0.002)) * 127.5; //can also use cos or tan
		unsigned char green = (1 + sin(elapsed * 0.001)) * 127.5;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 127.5;

		const Particle* const ptrParticle = Starz.getParticle();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle ptrfragments = ptrParticle[i];

			int x = (ptrfragments.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (ptrfragments.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			video.setPixel(x, y, red, green, blue);
		}

		//Draw Screen
		video.Update();
		//Check for messages/events
		if (video.processEvent() == false) {
			break;
		}
	}

	video.close();

	return 0;
}