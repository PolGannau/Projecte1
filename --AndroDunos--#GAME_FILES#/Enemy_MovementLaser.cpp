#include "Application.h"
#include "Enemy_MovementLaser.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_MovementLaser::Enemy_MovementLaser(int x, int y) : Enemy(x, y)
{
	type = MOVEMENTLASER;


	enemy.PushBack({ 0,329,30,22 });
	enemy.PushBack({ 75,329,30,22 });
	enemy.PushBack({ 0,372,30,22 });
	enemy.PushBack({ 75,372,30,22 });
	enemy.PushBack({ 0,417,30,22 });
	enemy.loop = false;
	enemy.speed = 0.1f;


	animation = &enemy;


	collider = App->collision->AddCollider({ 0, 0, 30, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_MovementLaser::Move()
{
	++time;
	if (time == 50) {
		App->enemies->AddEnemy(ENEMY_TYPES::LASER, position.x + 5, position.y - 172);
	}
}
void Enemy_MovementLaser::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}
