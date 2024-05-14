#pragma once
#include <vector>
#include <iostream>

#include "SDL_mixer.h"

#include "./imgui/imgui.h"
#include "./imgui/imgui_impl_sdl2.h"
#include "./imgui/imgui_impl_sdlrenderer2.h"

#include "./defs.h"
#include "./structs.h"

class App
{
public:
	App();
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool done, mbleft, kf1;
	int mouseX, mouseY;

	std::vector<Entity*> entities;

	void Update();
	void Render();
	void Display();
	void Clear();
	void Close();
private:
	bool pincelMenu, checkingRect, checkingLine, onMenu;
	short x, y, idPincel, mbcooldown, kf1cooldown;
	Vec3 color;
};