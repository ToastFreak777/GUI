#include "Swarm.h"
namespace Dust {
	Swarm::Swarm() {
		m_ptrParticles = new Particle[nParticles]; 
	}

	Swarm::~Swarm() {
		delete[] m_ptrParticles;
	}
}