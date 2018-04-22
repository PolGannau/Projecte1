#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleFonts.h"
#include "ModuleFadeToBlack.h"
#include "ModuleUI.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include <stdio.h>
#include "Gameover.h"
#include "ModuleSceneSpace.h"
#include "Stageclear.h"
#include "ModuleSceneIntro.h"

ModuleUi::ModuleUi() {}

ModuleUi::~ModuleUi() {}

bool ModuleUi::Start()
{
	LOG("Loading intro");

	user_interface = App->textures->Load("Assets/Sprites/user_interface.png");

	credits_rect.x = 0;
	credits_rect.y = 0;
	credits_rect.w = 45;//38 for credit
	credits_rect.h = 8;

	life1_rect.x = 46;
	life1_rect.y = 0;
	life1_rect.w = 7;
	life1_rect.h = 7;

	life2_rect.x = 54;
	life2_rect.y = 0;
	life2_rect.w = 7;
	life2_rect.h = 7;

	animationGameover = nullptr;

	gameover.PushBack({ 0,33,79,11 }); // x, y, w, h
	gameover.PushBack({ 80,33,79,11 });

	gameover.loop = true;
	gameover.speed = 0.0225f;

	animationPress1p = nullptr;

	press1p.PushBack({ 0,21,124,11 }); // x, y, w, h
	press1p.PushBack({ 125,21,124,11 });

	press1p.loop = true;
	press1p.speed = 0.0225f;

	animationPress2p = nullptr;

	press2p.PushBack({ 0,9,124,11 }); // x, y, w, h
	press2p.PushBack({ 125,9,124,11 });

	press2p.loop = true;
	press2p.speed = 0.0225f;

	//font_score = App->fonts->Load("Assets/font_score.png", "1234567890P", 1);


	return true;
}

bool ModuleUi::CleanUp()
{
	LOG("Unloading user interface")

		App->textures->Unload(user_interface);

	return true;
}
update_status ModuleUi::Update()
{



	//final score in stage
	//if (App->stageclear->IsEnabled() == true && App->gameover->IsEnabled() == false) {
	//	sprintf_s(score_text, 10, "%7d", App->player1->score);
	//	App->fonts->BlitText(20, 100, font_score, score_text);
	//}


	if (App->player->IsEnabled() == true) {

		if (App->player->hp == 3) {
			App->render->Blit(user_interface, 10, 20, &life1_rect, 0.0f);
			App->render->Blit(user_interface, 20, 20, &life1_rect, 0.0f);
		}
		if (App->player->hp == 2) {
			App->render->Blit(user_interface, 10, 20, &life1_rect, 0.0f);
		}
	}

	if (App->player2->IsEnabled() == true) {

		if (App->player2->hp == 3) {
			App->render->Blit(user_interface, 190, 20, &life2_rect, 0.0f);
			App->render->Blit(user_interface, 200, 20, &life2_rect, 0.0f);
		}
		if (App->player2->hp == 2) {
			App->render->Blit(user_interface, 190, 20, &life2_rect, 0.0f);
		}
	}
	return UPDATE_CONTINUE;
}