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
#include "SDL/include/SDL_timer.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	// idle animation (just the ship)
	idle.PushBack({ 154, 108, 27, 17 });

	stand_fire.PushBack({ 80,116,5,5 });
	stand_fire.PushBack({ 65,116,8,5 });
	stand_fire.PushBack({ 42,116,12,5 });
	stand_fire.loop = true;
	stand_fire.speed = 0.045f;

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

	position.x = App->player->position.x;
	position.y = App->player->position.y + 20;

	destroyed = false;
	// TODO 2: Add a collider to the player
	coll = App->collision->AddCollider({ position.x,position.y, 27, 16 }, COLLIDER_PLAYER, this);

	fx_1 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-1_(Main_Ships).wav");
	fx_2 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-2_(Main_Ships).wav");
	fx_3 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-3_(Main_Ships).wav");
	fx_4 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-4_(Main_Ships).wav");

	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(graphics);
	App->audio->UnloadSoundEffects(fx_1);
	App->audio->UnloadSoundEffects(fx_2);
	App->audio->UnloadSoundEffects(fx_3);
	App->audio->UnloadSoundEffects(fx_4);
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
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 50)
		{
			if (weapon1) {
				App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(fx_1);
			}
			else if (weapon2) {
				App->particles->AddParticle(App->particles->laser2right, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser2left, position.x - 7, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(fx_2);
			}
			else if (weapon3) {
				App->particles->AddParticle(App->particles->laser3, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(fx_3);
			}
			else if (weapon4) {
				App->particles->AddParticle(App->particles->laser4up, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser4down, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(fx_4);
			}
			lastTime = currentTime;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RSHIFT] == KEY_STATE::KEY_DOWN)
	{
		if (weapon1) {
			weapon1 = false;
			weapon2 = true;
		}
		else if (weapon2) {
			weapon2 = false;
			weapon3 = true;
		}
		else if (weapon3) {
			weapon3 = false;
			weapon4 = true;
		}
		else if (weapon4) {
			weapon4 = false;
			weapon1 = true;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		App->player->Enable();
		App->player->position.x = App->player2->position.x;
		App->player->position.y = App->player2->position.y - 20;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &idle;
	}

	// TODO 3: Update collider position to player position
	coll->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (App->player2->IsEnabled() == true)
	{
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		App->render->Blit(graphics, ((App->player2->position.x) - App->player2->stand_fire.GetCurrentFrame().w - 1), (App->player2->position.y + 7), &(stand_fire.GetCurrentFrame()));
	}

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == coll && destroyed == false && App->fade->IsFading() == false)
	{
		if (App->player->IsEnabled() == false)
		{
			App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->gameover,2.0f);
		}
		//code
		App->particles->AddParticle(App->particles->explosionship2, position.x, position.y, COLLIDER_NONE);
		weapon1 = true;
		App->player2->coll->to_delete = true;
		App->player2->Disable();
		App->player2->CleanUp();

	}
}