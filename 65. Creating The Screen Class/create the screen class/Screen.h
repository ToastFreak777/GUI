#pragma once
#include<iostream>
#include<SDL.h>
using namespace std;

namespace Dust {
	class Screen{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Render;
		SDL_Texture* m_Textures;
		Uint32* m_Buffer;
	};
}

