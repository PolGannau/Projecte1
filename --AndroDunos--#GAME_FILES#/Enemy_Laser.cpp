#include "Application.h"
#include "Enemy_Laser.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL/include/SDL_timer.h"

Enemy_Laser::Enemy_Laser(int x, int y) : Enemy(x, y)
{
	type = LASER;


	enemy.PushBack({ 266,398,20,306 });
	enemy.PushBack({ 311,398,20,306 });
	enemy.PushBack({ 356,398,20,306 });
	enemy.PushBack({ 401,398,20,306 });
	enemy.loop = false;
	enemy.speed = 0.1f;


	animation = &enemy;


	collider = App->collision->AddCollider({ 0, 0, 20, 306 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_y = y;
}
void Enemy_Laser::Move()
{

}
void Enemy_Laser::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_PLAYER) {
		App->player->position.y += 1;
	}
	if (collider->type == COLLIDER_PLAYER2) {
		App->player2->position.y += 1;
	}
}
