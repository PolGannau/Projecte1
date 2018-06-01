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

	SNK.PushBack({ 601,0,72,19 });
	SNK.PushBack({ 678,0,72,19 });
	SNK.PushBack({ 753,0,72,19 });
	SNK.PushBack({ 602,29,72,19 });
	SNK.PushBack({ 678,29,72,19 });
	SNK.PushBack({ 754,29,72,19 });
	SNK.PushBack({ 602,55,72,19 });
	SNK.PushBack({ 678,55,72,19 });
	SNK.PushBack({ 754,55,72,19 });
	SNK.PushBack({ 602,79,72,19 });
	SNK.PushBack({ 678,79,72,19 });
	SNK.PushBack({ 753,79,72,19 });
	SNK.PushBack({ 601,105,72,19 });
	SNK.PushBack({ 678,105,72,19 });
	SNK.PushBack({ 754,105,72,19 });
	SNK.PushBack({ 601,129,72,19 });
	SNK.PushBack({ 678,129,72,19 });
	SNK.PushBack({ 755,129,72,19 });
	SNK.loop = false;
	SNK.speed = 0.4f;
	
	Letters.PushBack({ 838,0,20,14 });
	Letters.PushBack({ 838,0,31,14 });
	Letters.PushBack({ 838,0,40,14 });
	Letters.PushBack({ 838,0,57,14 });
	Letters.PushBack({ 838,0,66,14 });
	Letters.PushBack({ 838,0,76,14 });
	Letters.PushBack({ 838,0,96,14 });
	Letters.PushBack({ 838,0,103,14 });
	Letters.PushBack({ 838,0,114,14 });
	Letters.PushBack({ 838,0,126,14 });
	Letters.loop = false;
	Letters.speed = 0.2f;

	Letters2.PushBack({ 838,17,8,13 });
	Letters2.PushBack({ 838,17,18,13 });
	Letters2.PushBack({ 838,17,31,13 });
	Letters2.PushBack({ 838,17,43,13 });
	Letters2.PushBack({ 838,17,55,13 });
	Letters2.PushBack({ 838,17,65,13 });
	Letters2.PushBack({ 838,17,77,13 });
	Letters2.PushBack({ 838,17,87,13 });
	Letters2.PushBack({ 838,17,102,13 });
	Letters2.PushBack({ 838,17,112,13 });
	Letters2.PushBack({ 838,17,121,13 });
	Letters2.PushBack({ 838,17,133,13 });
	Letters2.loop = false;
	Letters2.speed = 0.2f;

	Copy.PushBack({ 584,160,7,7 });
	Copy.loop = false;


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

	App->audio->PlayMusic(music,1);

	change = false;
	next = false;
	time2 = SDL_GetTicks();
	Neogeo.Reset();
	SNK.Reset();
	Letters.Reset();
	Letters2.Reset();
	Copy.Reset();
	time = 0;
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(intro);

	App->audio->UnloadMusic(music);
	change = false;
	Neogeo.Reset();
	SNK.Reset();
	Letters.Reset();
	Letters2.Reset();
	Copy.Reset();
	time = 0;


	return true;
}

// Update: draw background


	

update_status ModuleSceneIntro::Update()
{
	time = SDL_GetTicks() - time2;

	if (time > 1500) change = true;

	if (!change) {

		SDL_SetRenderDrawColor(App->render->renderer, 255, 255, 255, 0);
	}
	else {

		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	}

	SDL_RenderClear(App->render->renderer);

	anim = &Neogeo;
	anim2 = &SNK;
	anim3 = &Letters;
	anim4 = &Letters2;
	anim5 = &Copy;

	App->render->Blit(intro, 40, 50, &(anim->GetCurrentFrame()));

	if (time > 1700)
	{
		App->render->Blit(intro, 83, 120, &(anim3->GetCurrentFrame()));
		if (Letters.SeeCurrentFrame() == 9) {
			next = true;
		}
	}
	if (next) {
		App->render->Blit(intro, 83, 137, &(anim4->GetCurrentFrame()));
	}
	if (time > 4500 ) {
		App->render->Blit(intro, 112, 170, &(anim2->GetCurrentFrame()));
	}
	if (SNK.SeeCurrentFrame() > 14) {
		App->render->Blit(intro, 272, 52, &(anim5->GetCurrentFrame()));
	}
	
	if ((App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false) || time > 8000)
	{
		App->fade->FadeToBlack(this, (Module*)App->viscogames,0.0f);
	}
	if ((SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_START) && App->fade->IsFading() == false) || time > 8000) {
		App->fade->FadeToBlack(this, (Module*)App->viscogames, 0.0f);
	}

	return UPDATE_CONTINUE;
}