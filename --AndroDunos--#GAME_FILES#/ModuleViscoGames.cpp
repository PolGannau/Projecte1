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
	Visco.PushBack({ 32,88,189,39 });
	Visco.loop = false;

	Games.PushBack({ 15,128,223,39 });
	Games.loop = false;
}

ModuleViscoGames::~ModuleViscoGames()
{}

// Load assets
bool ModuleViscoGames::Start()
{
	LOG("Loading space intro");
	visco = App->textures->Load("assets/visco_games_intro.png");

	App->render->camera.x = App->render->camera.y = 0;

	if (App->scene_intro->IsEnabled() == true) {
		App->viscogames->Disable();
	}
		
	return true;
}

// UnLoad assets
bool ModuleViscoGames::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(visco);

	Visco.Reset();
	Games.Reset();


	return true;
}

// Update: draw background




update_status ModuleViscoGames::Update()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	anim = &Visco;
	anim2 = &Games;

	App->render->Blit(visco, 40, 50, &(anim->GetCurrentFrame()));
	App->render->Blit(visco, 40, 95, &(anim2->GetCurrentFrame()));

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START)) {
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}
	return UPDATE_CONTINUE;
}