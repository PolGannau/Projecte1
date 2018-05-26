#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleViscoGames.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL.h"


ModuleViscoGames::ModuleViscoGames()
{
	Games.x = 40;
	Games.y = -50;
	Games.w = 223;
	Games.h = 39;


	Visco.x = 57;
	Visco.y = 234;
	Visco.w = 189;
	Visco.h = 39;
	
}

ModuleViscoGames::~ModuleViscoGames()
{}

// Load assets
bool ModuleViscoGames::Start()
{
	LOG("Loading space intro");
	visco = App->textures->Load("assets/Visco.png");
	games = App->textures->Load("assets/Games.png");
	
	App->render->camera.x = App->render->camera.y = 0;
	if (App->scene_intro->IsEnabled() == true) {
		App->viscogames->Disable();
	}
	
	
	time2 = SDL_GetTicks();
	time = 0;
	
	return true;
}



// UnLoad assets
bool ModuleViscoGames::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(visco);
	App->textures->Unload(games);
	time = 0;


	return true;
}

// Update: draw background

update_status ModuleViscoGames::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}


update_status ModuleViscoGames::Update()
{
	time = SDL_GetTicks() - time2;
	

	if (movement == false) {
		Games.y += y;
		Visco.y -= y;
		
	}

	if (Games.y > 110)
	{
		y = 0;
		movement = true;
	}

	if (movement == true && time > 3900)
	{
		Games.x += x;
		Visco.x -= x;
		
	}
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START) && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}

	if (!App->render->Blit(games, Games.x, Games.y, NULL)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(visco, Visco.x, Visco.y, NULL)) return update_status::UPDATE_ERROR;
	return UPDATE_CONTINUE;
}