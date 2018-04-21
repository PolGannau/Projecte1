#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "Stageclear.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleStageclear::ModuleStageclear()
{
	stageclear.x = 108;
	stageclear.y = 232;
	stageclear.w = 304;
	stageclear.h = 48;
}

ModuleStageclear::~ModuleStageclear()
{}

// Load assets
bool ModuleStageclear::Start()
{
	LOG("Loading space intro");

	winscreen = App->textures->Load("assets/stageclear/StageClear-(1).png");

	App->render->camera.x = App->render->camera.y = 0;

	music = App->audio->LoadMusic("assets/stageclear/06_Stage_Clear.ogg");

	App->audio->PlayMusic(music, 1);

	return true;
}

// UnLoad assets
bool ModuleStageclear::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(winscreen);

	App->audio->UnloadMusic(music);

	return true;
}

// Update: draw background
update_status ModuleStageclear::Update()
{
	App->render->Blit(winscreen, 0, 88, &stageclear);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro, 0.2f);
	}

	return UPDATE_CONTINUE;
}