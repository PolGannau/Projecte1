#include "Application.h"
#include "Enemy_WhiteTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

Enemy_WhiteTurret::Enemy_WhiteTurret(int x, int y): Enemy(x, y)
{
	type = WHITETURRET;

	anim = 1;
	
	collider = App->collision->AddCollider({ 0, 0, 15, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	animation = &turret;
}

void Enemy_WhiteTurret::Move() 
{
	if (App->player->destroyed == false) {
		if (App->player->position.x < position.x) {
			if (App->player->position.y >= 0 && App->player->position.y < 20) {
				turret.Sprite({ 243,49,14,16 });
			}
			else if (App->player->position.y >= 20 && App->player->position.y < 60) {
				turret.Sprite({ 221,48,14,16 });
			}
			else if (App->player->position.y >= 60 && App->player->position.y < 90) {
				turret.Sprite({ 201,49,14,16 });
				App->particles->AddParticle(App->particles->TurretShot, position.x, position.y, COLLIDER_TYPE::COLLIDER_ENEMY_SHOT);
			}
			else if (App->player->position.y >= 90 && App->player->position.y < 150) {
				turret.Sprite({ 176,50,15,14 });
			}
			else {
				turret.Sprite({ 156,50,15,14 });
			}
		}
		else {
			if (App->player->position.y >= 0 && App->player->position.y < 20) {
				turret.Sprite({ 243,49,14,16 });
			}
			else if (App->player->position.y >= 20 && App->player->position.y < 60) {
				turret.Sprite({ 266,48,14,16 });
			}
			else if (App->player->position.y >= 60 && App->player->position.y < 90) {
				turret.Sprite({ 156,67,14,14 });
			}
			else if (App->player->position.y >= 90 && App->player->position.y < 150) {
				turret.Sprite({ 197,67,15,14 });
			}
			else {
				turret.Sprite({ 176,67,15,14 });
			}
		}
	}
	else {
		if (App->player2->position.x < position.x) {
			if (App->player2->position.y >= 0 && App->player2->position.y < 20) {
				turret.Sprite({ 243,49,14,16 });
			}
			else if (App->player2->position.y >= 20 && App->player2->position.y < 60) {
				turret.Sprite({ 221,48,14,16 });
			}
			else if (App->player2->position.y >= 60 && App->player2->position.y < 90) {
				turret.Sprite({ 201,49,14,16 });
			}
			else if (App->player2->position.y >= 90 && App->player2->position.y < 150) {
				turret.Sprite({ 176,50,15,14 });
			}
			else {
				turret.Sprite({ 156,50,15,14 });
			}
		}
		else {
			if (App->player2->position.y >= 0 && App->player2->position.y < 20) {
				turret.Sprite({ 243,49,14,16 });
			}
			else if (App->player2->position.y >= 20 && App->player2->position.y < 60) {
				turret.Sprite({ 266,48,14,16 });
			}
			else if (App->player2->position.y >= 60 && App->player2->position.y < 90) {
				turret.Sprite({ 156,67,14,14 });
			}
			else if (App->player2->position.y >= 90 && App->player2->position.y < 150) {
				turret.Sprite({ 197,67,15,14 });
			}
			else {
				turret.Sprite({ 176,67,15,14 });
			}
		}
	}
}
void Enemy_WhiteTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}