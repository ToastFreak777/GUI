#pragma once
#include<stdlib.h>
#include<time.h>

namespace Dust {
	struct Particle {	//keep in mind normally you wouldn't write out member variables like this, this example is just for the sake of efficiency
		double m_x;
		double m_y;
	public:
		Particle();

	};
}

/*
	THE ONLY DIFFERENCE BETWEEN A CLASS AND A STRUCT IS
		Member variables WITHIN A CLASS IS PRIVATE BY DEFAULT
		Member variables WITHIN A STRUCT IS PUBLIC BY DEFAULT

			A STRUCT IS A CLASS!

	Examples
		CLASS (class name){
			int x;
			int y;
		}
		the x and y will be private unless you write out public// vice versa for a struct

		STRUCT (class name){
			int x;
			int y;
		}
		the x and y will be public unless you write out private

		basically if you dont write out
			public:
			or
			private:
				then by default
					CLASS=Private
					STRUCT=Public
*/
