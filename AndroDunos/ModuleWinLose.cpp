#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWinLose.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleWinLose::ModuleWinLose()
{
	winlose.x = 0;
	winlose.y = 0;
	winlose.w = 700;
	winlose.h = 700;
}

ModuleWinLose::~ModuleWinLose()
{}

// Load assets
bool ModuleWinLose::Start()
{
	LOG("Loading space intro");

	stageclear = App->textures->Load("assets/winlose/StageClear-(1).png");

	App->render->camera.x = App->render->camera.y = 0;

	mus = App->audio->LoadMusic("assets/winlose/06_Stage_Clear.ogg");

	App->audio->PlayMusic(mus);

	return true;
}

// UnLoad assets
bool ModuleWinLose::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(stageclear);

	App->audio->UnloadMusic(mus);

	return true;
}

// Update: draw background
update_status ModuleWinLose::Update()
{
	/*App->render->Blit(stageclear, 0, 0, &winlose);

	if (App->input->keyboard[SDL_SCANCODE_] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene_intro, 0.1f);
	}*/

	return UPDATE_CONTINUE;
}