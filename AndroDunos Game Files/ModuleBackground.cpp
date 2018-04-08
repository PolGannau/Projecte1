#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{

	background1.x = 2;
	background1.y = 3;
	background1.w = 16;
	background1.h = 98;

	background2.x = 20;
	background2.y = 3;
	background2.w = 16;
	background2.h = 98;

	background3.x = 38;
	background3.y = 3;
	background3.w = 16;
	background3.h = 98;

	background4.x = 56;
	background4.y = 3;
	background4.w = 16;
	background4.h = 98;

	background5.x = 74;
	background5.y = 3;
	background5.w = 16;
	background5.h = 98;

	background6.x = 92;
	background6.y = 3;
	background6.w = 16;
	background6.h = 98;

	background7.x = 110;
	background7.y = 3;
	background7.w = 16;
	background7.h = 98;

	background8.x = 128;
	background8.y = 3;
	background8.w = 11;
	background8.h = 98;

	background9.x = 141;
	background9.y = 3;
	background9.w = 16;
	background9.h = 98;

	background10.x = 159;
	background10.y = 3;
	background10.w = 16;
	background10.h = 98;

	background11.x = 177;
	background11.y = 3;
	background11.w = 16;
	background11.h = 98;

	background12.x = 195;
	background12.y = 3;
	background12.w = 16;
	background12.h = 98;
	
	background13.x = 213;
	background13.y = 3;
	background13.w = 16;
	background13.h = 98;

	background14.x = 231;
	background14.y = 3;
	background14.w = 16;
	background14.h = 98;

	background15.x = 249;
	background15.y = 3;
	background15.w = 16;
	background15.h = 98;

	background16.x = 267;
	background16.y = 3;
	background16.w = 16;
	background16.h = 98;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Background_Tiles_part1.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	int pos_x = 0;
	// Draw everything --------------------------------------
	for (int i = 0; i < 200; ++i)
	{
		App->render->Blit(graphics, pos_x, 110, &background1, 0.75f); // sea and sky
		pos_x += background1.w;
		App->render->Blit(graphics, pos_x, 110, &background2, 0.75f);
		pos_x += background2.w;
		App->render->Blit(graphics, pos_x, 110, &background3, 0.75f);
		pos_x += background3.w;
		App->render->Blit(graphics, pos_x, 110, &background4, 0.75f);
		pos_x += background4.w;
		App->render->Blit(graphics, pos_x, 110, &background5, 0.75f);
		pos_x += background5.w;
		App->render->Blit(graphics, pos_x, 110, &background6, 0.75f);
		pos_x += background6.w;
		App->render->Blit(graphics, pos_x, 110, &background7, 0.75f);
		pos_x += background7.w;
		App->render->Blit(graphics, pos_x, 110, &background8, 0.75f);
		pos_x += background8.w;
		App->render->Blit(graphics, pos_x, 110, &background9, 0.75f);
		pos_x += background9.w;
		App->render->Blit(graphics, pos_x, 110, &background10, 0.75f);
		pos_x += background10.w;
		App->render->Blit(graphics, pos_x, 110, &background11, 0.75f);
		pos_x += background11.w;
		App->render->Blit(graphics, pos_x, 110, &background12, 0.75f);
		pos_x += background12.w;
		App->render->Blit(graphics, pos_x, 110, &background13, 0.75f);
		pos_x += background13.w;
		App->render->Blit(graphics, pos_x, 110, &background14, 0.75f);
		pos_x += background14.w;
		App->render->Blit(graphics, pos_x, 110, &background15, 0.75f);
		pos_x += background15.w;
		App->render->Blit(graphics, pos_x, 110, &background16, 0.75f);
		pos_x += background16.w;
	}


	return UPDATE_CONTINUE;
}