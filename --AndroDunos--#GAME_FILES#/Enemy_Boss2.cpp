#include "Application.h"
#include "Enemy_Boss2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Boss2::Enemy_Boss2(int x, int y) : Enemy(x, y)
{
	type = STRUCTBOSS;

	nomove.PushBack({ 20, 650, 66, 224 });
	nomove.PushBack({ 128, 650, 66, 224 });
	nomove.PushBack({ 236, 650, 66, 224 });
	nomove.speed = 0.2f;
	animation = &nomove;

	
	collider = App->collision->AddCollider({ 0, 0, 33, 224 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Boss2::Move()
{
	position.x += 0;
}
void Enemy_Boss2::OnCollision(Collider* collider) {}