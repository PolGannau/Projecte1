#include "Application.h"
#include "Enemy_WhiteTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

#include "SDL\include\SDL_timer.h"
#include <math.h>

Enemy_WhiteTurret::Enemy_WhiteTurret(int x, int y, bool up): Enemy(x, y)
{
	type = WHITETURRET;

	collider = App->collision->AddCollider({ 0, 0, 15, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	this->up = up;
	original_pos.x = x;
	original_pos.y = y;
	animation = &turret;
}

void Enemy_WhiteTurret::Move() 
{
	if (up) {
		if (App->player->IsEnabled()) {
			angle = (atan2(App->player->position.y - position.y, position.x - App->player->position.x) * 180) / 3.1418;
		}
		else {
			angle = (atan2(App->player2->position.y - position.y, position.x - App->player2->position.x) * 180) / 3.1418;
		}

		b = position.x - App->player->position.x;
		h = App->player->position.y - position.y;

		Time = SDL_GetTicks();

		if (Time > lastTime + 2500)
		{
			Shoot = true;
			lastTime = Time;

			if (b < -110) {
				Shoot = false;
			}
		}

		if (angle > -200 && angle <= -160) { //1
			turret.Sprite({ 176,67,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot9u, position.x + 12, position.y + 3, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -160 && angle <= -140) { //2
			turret.Sprite({ 197,67,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot8u, position.x + 9, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -140 && angle <= -120) { //3
			turret.Sprite({ 156,67,14,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot7u, position.x + 9, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -120 && angle <= -100) { //4 //
			turret.Sprite({ 266,48,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot6u, position.x + 6, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -100 && angle <= -80) { //5 
			turret.Sprite({ 243,49,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot5u, position.x + 3, position.y - 1, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -80 && angle <= -60) { //6
			turret.Sprite({ 221,48,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot4u, position.x + 3, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -60 && angle <= -40) { //7
			turret.Sprite({ 201,49,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot3u, position.x - 1, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > -40 && angle <= -20) { //8
			turret.Sprite({ 176,50,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot2u, position.x - 3, position.y, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else {									//9
			turret.Sprite({ 156,50,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot1u, position.x - 3, position.y + 3, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
	}
	else {
		if (App->player->IsEnabled()) {
			angle = (atan2(App->player->position.y - position.y, position.x - App->player->position.x) * 180) / 3.1418;
		}
		else {
			angle = (atan2(App->player2->position.y - position.y, position.x - App->player2->position.x) * 180) / 3.1418;
		}

		b = position.x - App->player->position.x;
		h = App->player->position.y - position.y;

		Time = SDL_GetTicks();

		if (Time > lastTime + 2500)
		{
			Shoot = true;
			lastTime = Time;

			if (b < -110) {
				Shoot = false;
			}
		}
		if (angle > -20 && angle <= 20) { // 1
			turret.Sprite({ 156,109,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot1d, position.x - 3, position.y + 6, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 20 && angle <= 40) { // 2
			turret.Sprite({ 176,109,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot2d, position.x - 2, position.y + 10, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 40 && angle <= 60) { // 3
			turret.Sprite({ 201,109,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot3d, position.x - 1, position.y + 12, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 60 && angle <= 80) { // 4
			turret.Sprite({ 221,109,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot4d, position.x + 3, position.y + 12, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 80 && angle <= 100) { // 5
			turret.Sprite({ 243,108,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot5d, position.x + 3, position.y + 16, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 100 && angle <= 120) { // 6
			turret.Sprite({ 266,109,14,16 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot6d, position.x + 6, position.y + 12, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 120 && angle <= 140) { // 7
			turret.Sprite({ 156,92,14,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot7d, position.x + 9, position.y + 12, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else if (angle > 140 && angle <= 160) { // 8
			turret.Sprite({ 197,92,15,14 });
			if (Shoot == true && b < 200) {
				App->particles->AddParticle(App->particles->TurretShot8d, position.x + 9, position.y + 10, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
		else {
			turret.Sprite({ 176,92,15,14 });
			if (Shoot == true && b < 200) { // 9
				App->particles->AddParticle(App->particles->TurretShot9d, position.x + 12, position.y + 6, COLLIDER_ENEMY_SHOT);
				Shoot = false;
			}
		}
	}
}






	

void Enemy_WhiteTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}