#include "app.h"

App::App()
{
	window = SDL_CreateWindow(
		APP_TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		0
	);

	renderer = SDL_CreateRenderer(
		window, -1, 0
	);

	done 		= false;
	pincelMenu 	= false;
	checkingRect= false;
	checkingLine= false;
	onMenu		= false;
	mbcooldown 	= 0;
}

void App::Update()
{
	mbcooldown-=2;
	if(idPincel != 2)
		checkingRect = false;

	/* Pixels */
	if (!ImGui::GetIO().WantCaptureMouse)
	{
	switch(idPincel)
	{
		case 0:
			if (mbleft)
			{
				Entity* pix = new Pixel(mouseX / APP_SCALE, mouseY / APP_SCALE, color.x, color.y, color.z);
				entities.emplace_back(pix);
			}
		break;
		case 1:
			if (mbleft && mbcooldown < 0)
			{
				if (!checkingLine)
				{
					//Mix_PlayChannel( -1, schbob, 0 );
					checkingLine = true;
					mbcooldown = 40;
					x = mouseX / APP_SCALE;
					y = mouseY / APP_SCALE;
				}
				else
				{
					short xx, yy;
					xx = mouseX / APP_SCALE;
					yy = mouseY / APP_SCALE;

					Entity* line = new Line(x, y, xx, yy, color.x, color.y, color.z);
					entities.emplace_back(line);

					checkingLine = false;
					mbcooldown = 40;
				}
			}
		break;
		case 2:
			if (mbleft && !checkingRect && mbcooldown < 0)
			{
				checkingRect = true;
				x = mouseX / APP_SCALE;
				y = mouseY / APP_SCALE;
				mbcooldown = 40;
			}
			if (mbleft && checkingRect && mbcooldown < 0)
			{
				short xx, yy;
				xx = mouseX / APP_SCALE-x;
				yy = mouseY / APP_SCALE-y;

				Entity* pix = new Rectangle(x, y, xx, yy, color.x, color.y, color.z);
				entities.emplace_back(pix);

				checkingRect = false;
				mbcooldown = 40;
			}
		break;
		case 3:
			std::cout << "hola";
		break;
	}
	}
	

	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->Draw(renderer);
	}

	/* UI */
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("Archivo"))
	{
		if (ImGui::MenuItem("Nuevo"))
		{
			entities.clear();
		}
		if (ImGui::MenuItem("Cargar"))
		{
			//
		}
		if (ImGui::MenuItem("Guardar"))
		{
			const Uint32 format = SDL_PIXELFORMAT_ARGB8888;
 	
    		SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, format);
    		SDL_RenderReadPixels(renderer, NULL, format, surface->pixels, surface->pitch);
    		IMG_SavePNG(surface, "screenshot.png");
    		SDL_FreeSurface(surface);
        }

		ImGui::Separator();

		if (ImGui::MenuItem("Salir"))
			done = true;

		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Dibujar"))
	{
		if (ImGui::MenuItem("Piceles"))
		{
			pincelMenu = pincelMenu-1;
        }
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();
	
	
	if (pincelMenu)
	{
		ImGui::Begin("Pinceles", &pincelMenu);
		if (ImGui::Button("Pixel"))
			idPincel = 0;
		ImGui::SameLine();
		if (ImGui::Button("Linea"))
			idPincel = 1;
		ImGui::SameLine();
		if (ImGui::Button("Rectangulo"))
			idPincel = 2;
		ImGui::SameLine();
		if (ImGui::Button("Circulo"))
			idPincel = 3;

		if (ImGui::CollapsingHeader("Color"))
		{
			ImGui::BulletText("hola");
			if (ImGui::Button("Negro"))
			{
				color.x = 0; 	// Rojo
				color.y = 0;	// Verde
				color.z = 0;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Blanco"))
			{
				color.x = 255; 	// Rojo
				color.y = 255;	// Verde
				color.z = 255;	// Azul
			}
			if (ImGui::Button("Rojo 1"))
			{
				color.x = 255; 	// Rojo
				color.y = 0;	// Verde
				color.z = 0;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Rojo 2"))
			{
				color.x = 150; 	// Rojo
				color.y = 0;	// Verde
				color.z = 0;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Verde 1"))
			{
				color.x = 0; 	// Rojo
				color.y = 255;	// Verde
				color.z = 0;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Verde 2"))
			{
				color.x = 0; 	// Rojo
				color.y = 150;	// Verde
				color.z = 0;	// Azul
			}
			if (ImGui::Button("Azul 1"))
			{
				color.x = 0; 	// Rojo
				color.y = 0;	// Verde
				color.z = 255;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Azul 2"))
			{
				color.x = 0; 	// Rojo
				color.y = 0;	// Verde
				color.z = 150;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Amarillo 1"))
			{
				color.x = 255; 	// Rojo
				color.y = 255;	// Verde
				color.z = 0;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Amarillo 2"))
			{
				color.x = 150; 	// Rojo
				color.y = 150;	// Verde
				color.z = 0;	// Azul
			}
			if (ImGui::Button("Morado 1"))
			{
				color.x = 255; 	// Rojo
				color.y = 0;	// Verde
				color.z = 255;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Morado 2"))
			{
				color.x = 150; 	// Rojo
				color.y = 0;	// Verde
				color.z = 150;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Cyan 1"))
			{
				color.x = 0; 	// Rojo
				color.y = 255;	// Verde
				color.z = 255;	// Azul
			}
			ImGui::SameLine();
			if (ImGui::Button("Cyan 2"))
			{
				color.x = 0; 	// Rojo
				color.y = 150;	// Verde
				color.z = 150;	// Azul
			}
		}
		ImGui::End();
	}
}

void App::Render()
{
	if (checkingRect)
	{
		SDL_Rect rectangle;
		rectangle.x = x;
		rectangle.y = y;
		rectangle.w = mouseX / APP_SCALE-x;
		rectangle.h = mouseY / APP_SCALE-y;
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, 15, 15, 15, 100);
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	}
	if (checkingLine)
	{
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, 15, 15, 15, 100);
		SDL_RenderDrawLine(renderer, x, y, mouseX / APP_SCALE, mouseY / APP_SCALE);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	}
}

void App::Display()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
}

void App::Clear()
{
	SDL_RenderClear(renderer);
}

void App::Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	for(int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}