#include "Swarm.h"
namespace Explosion {
	Swarm::Swarm() :lastTick(0) {
		m_ptrParticle = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_ptrParticle;
	}

	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTick;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_ptrParticle[i].update(interval);
		}

		lastTick = elapsed;
	}
}