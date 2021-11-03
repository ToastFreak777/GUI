#pragma once
#include<iostream>
#include<SDL.h>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

namespace Explosion {
	class Screen {
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
	public:
		Screen();
		~Screen();
		bool init();
		void Update();
		void clear();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool processEvent();
		void close();
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
		SDL_Texture* m_Texture;
		Uint32* m_Buffer;
	};
}