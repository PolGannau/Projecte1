#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"
#include "Stageclear.h"
#include "ModulePowerUps.h"
#include "PowerUpRed.h"
#include "PowerUp.h"
#include "SDL/include/SDL_timer.h"
#include<stdio.h>

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

	destroyed = false;
	position.x = 30;
	position.y = 60;
	score = 0;

	coll = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("assets/fonts/Font-score-white.png", "1234567890P", 1);

	fx_1 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-1_(Main_Ships).wav");
	fx_2 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-2_(Main_Ships).wav");
	fx_3 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-3_(Main_Ships).wav");
	fx_4 = App->audio->LoadEffect("assets/ship/Laser_Shot_Type-4_(Main_Ships).wav");

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->fonts->UnLoad(font_score);
	App->audio->UnloadSoundEffects(fx_1);
	App->audio->UnloadSoundEffects(fx_2);
	App->audio->UnloadSoundEffects(fx_3);
	App->audio->UnloadSoundEffects(fx_4);
	if (coll)
		coll->to_delete = true;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (position.x <= App->render->view.x)
		{
			position.x = App->render->view.x + 2;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (position.x + 27 >= App->render->view.x + App->render->view.w)
		{
			position.x = (App->render->view.x + App->render->view.w) - 28;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
		if (position.y + 17 >= App->render->view.y + App->render->view.h)
		{
			position.y = (App->render->view.y + App->render->view.h) - 18;
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
		if (position.y <= App->render->view.y)
		{
			position.y = App->render->view.y + 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 50)
		{
			if (App->powerups->powerup1) {
				if (weapon1) {
					App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser1powerupred, position.x + 10, position.y, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_1);
				}
				else if (weapon2) {
					App->particles->AddParticle(App->particles->laser2right, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser2left, position.x - 7, position.y + 7, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser2powerupred, position.x +10, position.y, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_2);
				}
				else if (weapon3) {
					App->particles->AddParticle(App->particles->laser3, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser3powerupred, position.x + 10, position.y, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_3);
				}
				else if (weapon4) {
					App->particles->AddParticle(App->particles->laser4up, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4down, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4powerupredup, position.x + 10, position.y, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4powerupreddown, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_4);
				}
			}
			else if (App->powerups->powerup2) {
				if (weapon1) {
					App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser, position.x + 25, position.y + 11, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 18, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_1);
				}
				else if (weapon2) {
					App->particles->AddParticle(App->particles->laser2right, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser2left, position.x - 7, position.y + 6, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser2left, position.x - 7, position.y + 12, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_2);
				}
				else if (weapon3) {
					App->particles->AddParticle(App->particles->laser3, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_3);
				}
				else if (weapon4) {
					App->particles->AddParticle(App->particles->laser4up, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4down, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4powerupblue, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_4);
				}
			}
			else {
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
					App->particles->AddParticle(App->particles->laser4up, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser4down, position.x + 20, position.y + 10.5, COLLIDER_PLAYER_SHOT);
					App->audio->PlaySoundEffect(fx_4);
				}
			}
			score += 13;
			lastTime = currentTime;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

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

		if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_DOWN)
		{
			App->player2->Enable();
		}

	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->stageclear);
	}

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->gameover);
	}

	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN)
	{
		App->enemies->AddEnemy(ENEMY_TYPES::SHIPUPDOWN, position.x + 250, position.y);
		App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, position.x + 250, position.y);
	}

	coll->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		App->render->Blit(graphics, ((App->player->position.x) - App->player->stand_fire.GetCurrentFrame().w - 1), (App->player->position.y + 7), &(stand_fire.GetCurrentFrame()));
	}
	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);


	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == coll && destroyed == false && App->fade->IsFading() == false)
	{
		if (App->player2->IsEnabled() == false)
		{
			App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->gameover, 2.0f);
		}

		App->particles->AddParticle(App->particles->explosionship, position.x, position.y, COLLIDER_NONE);

		App->player->coll->to_delete = true;
		weapon1 = true;
		App->player->Disable();
		App->player->CleanUp();

		destroyed = true;
	}
}