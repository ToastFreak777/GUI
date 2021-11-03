#pragma once
#include<iostream>
#include<SDL.h>
#include<cmath>
using namespace std;

namespace Dust {

	class Screen {
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Render;
		SDL_Texture* m_Texture;
		Uint32* m_Buffer;

	public:
		Screen();
		bool init();
		void Update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool processEvents();
		void close();
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	};
}


