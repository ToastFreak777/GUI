#pragma once
#include"Particle.h"

namespace Wave {
	class Swarm {
	public:
		Swarm();
		~Swarm();
		void update(int elapsed);
		const static int NPARTICLES = 5000;
		const Particle* const getParticle() { return m_ptrParticle; }

	private:
		Particle* m_ptrParticle;
		int lastTick;
	};
}

