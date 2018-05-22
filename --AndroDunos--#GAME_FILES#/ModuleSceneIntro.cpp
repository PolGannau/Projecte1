#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{
	/*neogeo.x = 0;
	neogeo.y = 0;
	neogeo.w = 512;
	neogeo.h = 512;*/
	
	Neogeo.PushBack({0,0,250,40});
	Neogeo.PushBack({ 0,90,250,40 });
	Neogeo.PushBack({ 0,190,250,40 });
	Neogeo.PushBack({ 0,290,250,40 });
	Neogeo.PushBack({ 0,390,250,40 });
	Neogeo.PushBack({ 0,490,250,40 });
	Neogeo.PushBack({ 0,590,250,40 });
	Neogeo.PushBack({ 0,690,250,40 });
	Neogeo.PushBack({ 0,790,250,40 });
	Neogeo.PushBack({ 0,890,250,40 });
	Neogeo.PushBack({ 0,990,250,40 });
	Neogeo.PushBack({ 0,1090,250,40 });
	Neogeo.PushBack({ 0,1190,250,40 });
	Neogeo.PushBack({ 0,1290,250,40 });
	Neogeo.PushBack({ 0,1390,250,40 });
	Neogeo.PushBack({ 0,1490,250,40 });
	Neogeo.PushBack({ 0,1590,250,40 });
	Neogeo.PushBack({ 0,1690,250,40 });
	Neogeo.PushBack({ 0,1790,250,40 });
	Neogeo.PushBack({ 0,1890,250,40 });
	Neogeo.PushBack({ 0,1990,250,40 });
	Neogeo.PushBack({ 0,2090,250,40 });
	Neogeo.PushBack({ 0,2190,250,40 });
	Neogeo.PushBack({ 0,2290,250,40 });
	Neogeo.PushBack({ 0,2390,250,40 });
	Neogeo.PushBack({ 350,0,250,40 });
	Neogeo.PushBack({ 350,90,250,40 });
	Neogeo.PushBack({ 350,190,250,40 });
	Neogeo.PushBack({ 350,290,250,40 });
	Neogeo.PushBack({ 350,390,250,40 });
	Neogeo.PushBack({ 350,490,250,40 });
	Neogeo.PushBack({ 350,590,250,40 });
	Neogeo.PushBack({ 350,690,250,40 });
	Neogeo.PushBack({ 350,790,250,40 });
	Neogeo.PushBack({ 350,890,250,40 });
	Neogeo.PushBack({ 350,990,250,40 });
	Neogeo.PushBack({ 350,1090,250,40 });
	Neogeo.PushBack({ 350,1190,250,40 });
	Neogeo.PushBack({ 350,1290,250,40 });
	Neogeo.PushBack({ 350,1390,250,40 });
	Neogeo.PushBack({ 350,1490,250,40 });
	Neogeo.PushBack({ 350,1590,250,40 });
	Neogeo.PushBack({ 350,1690,250,40 });
	Neogeo.PushBack({ 350,1790,250,40 });
	Neogeo.PushBack({ 350,1890,250,40 });
	Neogeo.PushBack({ 350,1990,250,40 });
	Neogeo.PushBack({ 350,2090,250,40 });

	Neogeo.loop = false;
	Neogeo.speed = 0.4f;

}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");

	intro = App->textures->Load("assets/Intro/Neogeo.png");

	App->render->camera.x = App->render->camera.y = 0;

	music = App->audio->LoadMusic("assets/Intro/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music);
	time2 = SDL_GetTicks();
	time = 0;
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);

	App->audio->UnloadMusic(music);
	Neogeo.Reset();
	time = 0;
	change = false;

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::PreUpdate() {

	time = SDL_GetTicks() - time2;

	if (time > 1500) change = true;

	if (!change) {

		SDL_SetRenderDrawColor(App->render->renderer, 255, 255, 255, 0);
	}
	else {

		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	}

	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}
update_status ModuleSceneIntro::Update()
{
	time = SDL_GetTicks() - time2;
	anim = &Neogeo;

	App->render->Blit(intro, 40, 50, &(anim->GetCurrentFrame()));
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage2,0.0f);
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START)) {
		App->fade->FadeToBlack(this, (Module*)App->stage2, 0.0f);
	}

	return UPDATE_CONTINUE;
}