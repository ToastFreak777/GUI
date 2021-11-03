#pragma once
#include"Screen.h"
namespace Explosion {
	struct Particle {
		double m_x;
		double m_y;

		double m_speed;
		double m_direction;

	public:
		Particle();
		~Particle();
		void Update();
	};
}


