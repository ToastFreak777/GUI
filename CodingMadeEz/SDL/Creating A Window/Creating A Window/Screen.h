#pragma once
#include <iostream>
#include<SDL.h>
using namespace std;

class Screen{
public:
	const static int Screen_Width = 800;
	const static int Screen_Height = 600;
public:
	Screen();
	virtual ~Screen();
	bool init();

private:
	SDL_Window* mWindow;
};

