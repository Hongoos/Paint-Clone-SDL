#include "input.h"

void DoKeyUp(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
			/*
		}
		case SDL_SCANCODE_UP:
		case SDL_SCANCODE_W:
			app.up = false;
			break;

		case SDL_SCANCODE_DOWN:
		case SDL_SCANCODE_S:
			app.down = false;
			break;

		case SDL_SCANCODE_LEFT:
		case SDL_SCANCODE_A:
			app.left = false;
			break;

		case SDL_SCANCODE_RIGHT:
		case SDL_SCANCODE_D:
			app.right = false;
			break;
		*/
		
		}
	}
}

void DoKeyDown(SDL_KeyboardEvent* event)
{
	if (event->repeat == 0)
	{
		switch (event->keysym.scancode)
		{
		case SDL_SCANCODE_F1:
			switch(app.kf1)
			{
				case true:
					app.kf1 = false;
				break;
				case false:
					app.kf1 = true;
				break;
			}
		break;

		case SDL_SCANCODE_F11:
			//SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);
			auto flag = SDL_GetWindowFlags(app.window);
			auto is_fullscreen  = flag&SDL_WINDOW_FULLSCREEN;
			if(is_fullscreen == SDL_WINDOW_FULLSCREEN)
			{
				SDL_SetWindowFullscreen(app.window, 0);
			}
			else
			{
				SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN);
			}
		break;
			/*
		case SDL_SCANCODE_UP:
		case SDL_SCANCODE_W:
			app.up = true;
		break;

		case SDL_SCANCODE_DOWN:
		case SDL_SCANCODE_S:
			app.down = true;
		break;

		case SDL_SCANCODE_LEFT:
		case SDL_SCANCODE_A:
			app.left = true;
		break;

		case SDL_SCANCODE_RIGHT:
		case SDL_SCANCODE_D:
			app.right = true;
		break;
		*/
		}
	}
}

void DoInput(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&app.mouseX, &app.mouseY);
		break;
		case SDL_MOUSEBUTTONUP:
			app.mbleft = false;
		break;

		case SDL_MOUSEBUTTONDOWN:
			app.mbleft = true;
		break;
		case SDL_QUIT:
			app.done = true;
		break;

		case SDL_KEYDOWN:
			DoKeyDown(&event.key);
		break;

		case SDL_KEYUP:
			DoKeyUp(&event.key);
		break;

		default:
		break;
		}
	}
}