#include "Particle.h"
namespace Wave {
	Particle::Particle() :m_x(0), m_y(0) {
		init();
	}
	Particle::~Particle() {

	}

	void Particle::init() {
		m_x = 0;
		m_y = 0;

		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * M_PI * rand()) / RAND_MAX;

		m_speed *= m_speed;
	}

	void Particle::update(int interval) {
		m_direction += interval * 0.0003;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;

		if (m_x < -1 || m_x>1 || m_y < -1 || m_y>1) {
			init(); //causes particles that go off the edge of screen to reappear in the center again reducing the look of the particles being sucked in
		}

		if (rand() < RAND_MAX / 100) {
			init();		//this will cause the program to randomly re produce particles making the effect more dynamic
		}
	}
}