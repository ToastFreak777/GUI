#pragma once
#include"Screen.h"

namespace Wave {
	struct Particle{
		double m_x;
		double m_y;

	public:
		Particle();
		~Particle();
		void update(int interval);

	private:
		double m_direction;
		double m_speed;

	private:
		void init();
	};
}
/*
THE ONLY DIFFERENCE BETWEEN A CLASS AND A STRUCT IS
		Member variables WITHIN A CLASS IS PRIVATE BY DEFAULT
		Member variables WITHIN A STRUCT IS PUBLIC BY DEFAULT
*/

