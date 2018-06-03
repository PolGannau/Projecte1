#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	type = BOSS;

	/*nomove.PushBack({ 20, 650, 66, 224 });
	nomove.PushBack({ 128, 650, 66, 224 });
	nomove.PushBack({ 236, 650, 66, 224 });
	nomove.speed = 0.2f;
	//animation = &nomove;*/

	boss.PushBack({19,900,66,128});
	boss.PushBack({ 128,900,66,128 });
	boss.PushBack({ 236,900,66,128 });
	boss.speed = 0.1f;

	animation = &boss;
	collider = App->collision->AddCollider({ 0, 0, 66, 128 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Boss::Move()
{
	position.x += 0;
}
void Enemy_Boss::OnCollision(Collider* collider) {}
