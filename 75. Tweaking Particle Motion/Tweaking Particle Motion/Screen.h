#pragma once
#include<iostream>
#include<SDL.h>
#include<stdlib.h>
#include<cmath>
#include<time.h>
using namespace std;

namespace Wave {
	class Screen{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

		Screen();
		~Screen();
		bool init();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void update();
		void boxBlur();
		bool processEvent();
		void close();
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
		SDL_Texture* m_Textures;
		Uint32* m_Buffer1;
		Uint32* m_Buffer2;
	};
}

