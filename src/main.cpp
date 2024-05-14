#include "main.h"

App app = App();
Mix_Chunk* schbob 	= Mix_LoadWAV("schbob.wav");
Mix_Chunk* schpoom 	= Mix_LoadWAV("schpoom.wav");
Mix_Chunk* schmeow 	= Mix_LoadWAV("schmeow.wav");

/* Lock 60 FPS */
void CapFrameRate(long* then, float* remainder)
{
	long wait, frameTime;
	wait = 16 + *remainder;
	*remainder -= (int)*remainder;
	frameTime = SDL_GetTicks() - *then;
	wait -= frameTime;
	if (wait < 1)
		wait = 1;
	SDL_Delay(wait);
	*remainder += 0.667;
	*then = SDL_GetTicks();
}

void Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
}

int main(int argc, char *argv[])
{
	if (schbob == NULL)
		std::cout << "hola\n";
	Init();
	/* ImGui Initialize */
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(app.window, app.renderer);
    ImGui_ImplSDLRenderer2_Init(app.renderer);

    long then;
	float remainder;

	while(!app.done)
	{

		/* Update */
		then = SDL_GetTicks();

		DoInput();

		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		app.Update();

		/* Render */
		app.Render();
		SDL_RenderSetScale(app.renderer, 1.0f, 1.0f);
		ImGui::Render();
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
		SDL_RenderSetScale(app.renderer, APP_SCALE, APP_SCALE);
		app.Display();
		app.Clear();

		CapFrameRate(&then, &remainder);
	}

	/* Quit Dear ImGui */
	ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    /* Quit SDL2 */
	app.Close();
	SDL_Quit();
	return 0;
}