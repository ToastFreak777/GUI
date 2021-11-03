#include "Swarm.h"
namespace Dust {
	Swarm::Swarm() {
		m_ptrParticle = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_ptrParticle;
	}

	void Swarm::Update() {
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_ptrParticle[i].Update();
		}
	}
}
