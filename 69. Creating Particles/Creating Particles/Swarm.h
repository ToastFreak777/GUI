#pragma once
#include"Particle.h"
namespace Dust {
	class Swarm{
	private:
		Particle* m_ptrParticles;
	public:
		Swarm();
		~Swarm();
		const static int nParticles = 5000; // this will  allocate memory for the number of particles I want to create.
		//const Particle* const getParticle() { return m_ptrParticles; }
	};
}

/*
REMEMBER
	1. Particle* const getParticle() means a constant pointer
	2. const Particle* means a constant particle

		1. means the info its pointing at cannot be changed
		2. means the pointer itself cannot be changed
*/
