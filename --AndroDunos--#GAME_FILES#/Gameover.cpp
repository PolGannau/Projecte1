#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "Gameover.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleGameover::ModuleGameover()
{
	gameover.x = 8;
	gameover.y = 105;
	gameover.w = 240;
	gameover.h = 40;
}

ModuleGameover::~ModuleGameover()
{}

// Load assets
bool ModuleGameover::Start()
{
	LOG("Loading space intro");

	losescreen = App->textures->Load("assets/gameover/GameOver (115).png");

	App->render->camera.x = App->render->camera.y = 0;

	music = App->audio->LoadMusic("assets/gameover/18_Game_Over.ogg");

	App->audio->PlayMusic(music, 1);

	return true;
}

// UnLoad assets
bool ModuleGameover::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(losescreen);

	App->audio->UnloadMusic(music);

	return true;
}

// Update: draw background
update_status ModuleGameover::Update()
{
	App->render->Blit(losescreen, 32, 92, &gameover);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro, 0.2f);
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START)) {
		App->fade->FadeToBlack(this, (Module*)App->scene_intro, 0.2f);
	}

	return UPDATE_CONTINUE;
}