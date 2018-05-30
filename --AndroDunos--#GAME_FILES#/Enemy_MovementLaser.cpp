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


	collider = App->collision->AddCollider({ 0, 0, 44, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_MovementLaser::Move()
{

}
void Enemy_MovementLaser::OnCollision(Collider* collider) {

}
