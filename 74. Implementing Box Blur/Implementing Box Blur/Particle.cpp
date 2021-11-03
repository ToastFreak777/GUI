#include "Particle.h"
namespace Explosion {
	Particle::Particle() :m_x(0), m_y(0) {
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.0001 * M_PI * rand()) / RAND_MAX;
	}

	Particle::~Particle() {

	}

	void Particle::update(int interval) {
		double xSpeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xSpeed * interval;
		m_y += yspeed * interval;
	}
}