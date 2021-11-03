#include "Particle.h"

namespace Dust {
	Particle::Particle() {
		m_x = ((2.0 * rand()) / RAND_MAX) - 1; //what prof was trying to do was set the range from -1 to 1. There might be a better way to do this code try experimenting with it.
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;
	}
}
