#include "Screen.h"
namespace Dust {
	Screen::Screen() :m_Window(NULL), m_Renderer(NULL), m_Textures(NULL), m_Buffer(NULL) {

	};

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			return false;
		}

		m_Window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL) {
			SDL_Quit();
			return false;
		};

		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_Textures = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (m_Renderer == NULL) {
			SDL_DestroyWindow(m_Window);
			SDL_Quit();
			return false;
		}
		if (m_Textures == NULL) {
			SDL_DestroyRenderer(m_Renderer);
			SDL_DestroyWindow(m_Window);
			SDL_Quit();
			return false;
		}

		m_Buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		memset(m_Buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::Update() {
		SDL_UpdateTexture(m_Textures, NULL, m_Buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_Renderer);
		SDL_RenderCopy(m_Renderer, m_Textures, NULL, NULL);
		SDL_RenderPresent(m_Renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
			return;
		}	//this will make it so it will not plot pixels outside of the screen and will instead return the pixels that would be put outside of the screen and only plot it if its inside the screen
		//this is inefficient though according to prof.

		Uint32 Color = 0;

		Color += red;
		Color <<= 8;
		Color += green;
		Color <<= 8;
		Color += blue;
		Color <<= 8;
		Color += 0xFF;

		m_Buffer[(y * SCREEN_WIDTH) + x]=Color;
	}

	bool Screen::processEvent() {
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
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyTexture(m_Textures);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}
}