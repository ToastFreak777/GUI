#include "Screen.h"

namespace Dust {
	Screen::Screen() : m_Window(NULL), m_Render(NULL), m_Textures(NULL), m_Buffer(NULL) {

	}

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_Window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL) {
			SDL_Quit();
			return false;
		}

		m_Render = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_Textures = SDL_CreateTexture(m_Render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_Render == NULL) {
			SDL_DestroyWindow(m_Window);
			SDL_Quit();
			return false;
		}

		if (m_Textures == NULL) {
			SDL_DestroyRenderer(m_Render);
			SDL_DestroyWindow(m_Window);
			SDL_Quit();
			return false;
		}

		m_Buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(m_Buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		Uint32 Color = 0;

		Color += red;
		Color <<= 8;
		Color += green;
		Color <<= 8;
		Color += blue;
		Color <<= 8;
		Color += 0xFF;

		m_Buffer[(y * SCREEN_WIDTH) + x] = Color;
	}

	void Screen::Update() {
		SDL_UpdateTexture(m_Textures, NULL, m_Buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_Render);
		SDL_RenderCopy(m_Render, m_Textures, NULL, NULL);
		SDL_RenderPresent(m_Render);
	}

	bool  Screen::processEvents() {
		SDL_Event Events;
		while (SDL_PollEvent(&Events)) {
			if (Events.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}

	void Screen::close() {
		delete[] m_Buffer;
		SDL_DestroyRenderer(m_Render);
		SDL_DestroyTexture(m_Textures);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}
}