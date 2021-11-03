#include "Screen.h"

namespace Wave {
	Screen::Screen() :m_Window(NULL), m_Renderer(NULL), m_Textures(NULL), m_Buffer1(NULL), m_Buffer2(NULL) {

	}

	Screen::~Screen() {

	}

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			return false;
		}

		m_Window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL) {
			SDL_Quit();
			return false;
		}

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

		m_Buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		m_Buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		memset(m_Buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		memset(m_Buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_Textures, NULL, m_Buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_Renderer);
		SDL_RenderCopy(m_Renderer, m_Textures, NULL, NULL);
		SDL_RenderPresent(m_Renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {	//doesnt allow pixels to go outside of program
			return;
		}

		Uint32 Color = 0;

		Color += red;
		Color <<= 8;
		Color += green;
		Color <<= 8;
		Color += blue;
		Color <<= 8;
		Color += 0xFF;

		m_Buffer1[(y * SCREEN_WIDTH) + x] = Color;
	}

	void Screen::boxBlur() {
		Uint32* ptrtemp = m_Buffer1;
		m_Buffer1 = m_Buffer2;
		m_Buffer2 = ptrtemp;

		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				/*
					0 0 0
					0 P 0		this is a visual representation of box blur.	All the elements represent a single pixel(both the P and the 0s).
					0 0 0		the P is just there to show which pixel we will not be applying blur to.
							so we will be applying blur to all the 0s of the box blur but not the P.
				*/
				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;

				for (int row = -1; row <= 1; row++) {
					for (int column = -1; column <= 1; column++) {
						int xPixel = x + column;
						int yPixel = y + row;

						if (xPixel >= 0 && xPixel < SCREEN_WIDTH && yPixel >= 0 && yPixel < SCREEN_HEIGHT) {
							Uint32 Color = m_Buffer2[(yPixel * SCREEN_WIDTH) + xPixel];

							Uint8 red = Color >> 24;
							Uint8 green = Color >> 16;
							Uint8 blue = Color >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal += blue;
						}
					}
				}
				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;

				setPixel(x, y, red, green, blue);
			}
		}
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
		delete[] m_Buffer1;
		delete[] m_Buffer2;
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyTexture(m_Textures);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}
}