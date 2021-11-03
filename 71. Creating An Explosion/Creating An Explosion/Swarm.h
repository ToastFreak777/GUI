#pragma once
#include"Particle.h"

namespace Explosion {
	class Swarm {
	public:
		Swarm();
		~Swarm();
		const static int NPARTICLES = 5000;
		const Particle* const getParticle() { return m_ptrParticle; }
		void Update();
	private:
		Particle* m_ptrParticle;
	};
}


