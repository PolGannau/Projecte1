#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 110;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 95, 106, 28, 24 });
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	upward.PushBack({ 95, 106, 28, 24 });
	upward.PushBack({ 95, 82, 28, 24 });
	upward.PushBack({ 95, 60, 28, 24 });
	upward.speed = 0.1f;

	downward.PushBack({ 95, 106, 28, 24 });
	downward.PushBack({ 95, 126, 28, 24 });
	downward.PushBack({ 95, 148, 28, 24 });
	downward.speed = 0.1f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ships.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		position.x += speed;
	}
	else if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		position.x -= speed;
	}
	else if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &upward;
		position.y -= speed;
	}
	else if (App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		current_animation = &downward;
		position.y += speed;
	}

	position.x += speed;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}