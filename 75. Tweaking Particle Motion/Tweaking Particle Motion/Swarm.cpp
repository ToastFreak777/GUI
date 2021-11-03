#include "Swarm.h"
namespace Wave {
	Swarm::Swarm():lastTick(0) {
		m_ptrParticle = new Particle[NPARTICLES];
	}
	Swarm::~Swarm() {
		delete[] m_ptrParticle;
	}

	void Swarm::update(int elapsed) {
		int Interval = elapsed - lastTick;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_ptrParticle[i].update(Interval);
		}

		lastTick = elapsed;
	}
}