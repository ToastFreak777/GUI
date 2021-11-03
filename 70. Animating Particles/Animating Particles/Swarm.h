#pragma once
#include"Particle.h"
namespace Dust {
	class Swarm {
	public:
		Swarm();
		~Swarm();
		const static int NPARTICLES = 1000;
		const Particle* const getParticle() { return m_ptrParticle; }
		void Update();
	private:
		Particle* m_ptrParticle;
	};
}


