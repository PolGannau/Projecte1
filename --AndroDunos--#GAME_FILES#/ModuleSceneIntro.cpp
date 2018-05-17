#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{
	neogeo.x = 0;
	neogeo.y = 0;
	neogeo.w = 512;
	neogeo.h = 512;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");

	intro = App->textures->Load("assets/Intro/Neogeo (47).png");

	App->render->camera.x = App->render->camera.y = 0;

	music = App->audio->LoadMusic("assets/Intro/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music);

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);

	App->audio->UnloadMusic(music);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(intro, 0, 0, &neogeo);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage2,0.0f);
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START)) {
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}

	return UPDATE_CONTINUE;
}