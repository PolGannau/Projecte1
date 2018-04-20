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
#include "ModuleEnemies.h"
#include "ModuleWinLose.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	idle.PushBack({ 94, 108, 27, 17 });

	stand_fire.PushBack({ 80,116,5,5 });
	stand_fire.PushBack({ 65,116,8,5 });
	stand_fire.PushBack({ 42,116,12,5 });
	stand_fire.loop = true;
	stand_fire.speed = 0.045f;

	// move upwards
	up.PushBack({ 94, 88, 27, 15 });
	up.PushBack({ 94, 67, 27, 15 });
	up.loop = false;
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 94, 132, 27, 16 });
	down.PushBack({ 94, 154, 27, 17 });
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("assets/ship/ships.png");

	position.x = 30;
	position.y = 60;

	// TODO 2: Add a collider to the player
	coll = App->collision->AddCollider({ position.x,position.y, 27, 16 },COLLIDER_PLAYER, this);

	fx_1 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-1_(Main_Ships).wav");
	fx_2 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-2_(Main_Ships).wav");
	fx_3 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-3_(Main_Ships).wav");
	fx_4 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-4_(Main_Ships).wav");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
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
update_status ModulePlayer::Update()
{
	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{

		if (weapon1) {
			App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->laser, position.x + 20, position.y +11, COLLIDER_PLAYER_SHOT);
			App->audio->PlaySoundEffect(fx_1);
		}
		else if (weapon2) {
			App->particles->AddParticle(App->particles->laser2right, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
			App->particles->AddParticle(App->particles->laser2left, position.x -7, position.y + 7, COLLIDER_PLAYER_SHOT);
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
	}

	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN)
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
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
	{
		current_animation = &idle;
	}

	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_DOWN)
	{
		App->player2->Enable();
	}

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN)
	{
		if (collision)
		{
			coll = App->collision->AddCollider({ position.x,position.y,27, 16 }, COLLIDER_PLAYER, this);
			if (App->player2->IsEnabled() == true)
			{
				App->player2->coll = App->collision->AddCollider({ App->player2->position.x,App->player2->position.y,27,16 }, COLLIDER_PLAYER, App->player2);
			}
			collision = false;
		}
		else
		{
			App->player->coll->to_delete = true;
			if (App->player2->IsEnabled() == true)
			{
				App->player2->coll->to_delete = true;
			}
			collision = true;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->scene_space, App->winlose, 1.0f);
	}
	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, position.x+250, position.y);
	}

	

	// TODO 3: Update collider position to player position
	coll->SetPos(position.x,position.y);

	if (App->player->position.x <= App->render->camera.x)
	{
		App->player->position.x = App->render->camera.x;
	}


	// Draw everything --------------------------------------
	if (App->player->IsEnabled() == true)
	{
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	}

	App->render->Blit(graphics, ((App->player->position.x) - App->player->stand_fire.GetCurrentFrame().w - 1), (App->player->position.y + 7), &(stand_fire.GetCurrentFrame()));

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a wall. If so, go back to intro screen.

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == coll && destroyed == false && App->fade->IsFading() == false)
	{
		if (App->player2->IsEnabled() == false) 
		{
			App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->scene_intro, 3.0f);
		}
		//code
		App->particles->AddParticle(App->particles->explosionship, position.x, position.y, COLLIDER_NONE);
		App->player->coll->to_delete = true;
		App->player->Disable();
		App->player->CleanUp();

	}
}