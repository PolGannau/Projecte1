#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleSceneIntro.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	// idle animation (just the ship)
	idle.PushBack({ 154, 108, 27, 17 });

	// move upwards
	up.PushBack({ 154, 87, 27, 15 });
	up.PushBack({ 154, 66, 27, 15 });
	up.loop = false;
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 154, 131, 27, 16 });
	down.PushBack({ 154, 153, 27, 17 });
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player2");
	bool ret = true;
	bool insert2 = false;

	graphics = App->textures->Load("assets/ship/ships.png");

	position.x = App->render->camera.x + 30;
	position.y = App->render->camera.y + 120;

	destroyed = false;
	// TODO 2: Add a collider to the player
	coll = App->collision->AddCollider({ position.x,position.y, 27, 16 }, COLLIDER_PLAYER);

	fx = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-1_(Main_Ships).wav");

	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(graphics);
	App->audio->UnloadSoundEffects(fx);
	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
		App->audio->PlaySoundEffect(fx);
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &idle;
	}

	// TODO 3: Update collider position to player position
	coll->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == coll && destroyed == false && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->scene_intro);
		//code
		App->player2->Disable();

	}
}