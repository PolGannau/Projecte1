#include "Application.h"
#include "Enemy_WhiteYellow.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_WhiteYellow::Enemy_WhiteYellow(int x, int y) : Enemy(x, y)
{
	type = WHITEYELLOW;

	fly.PushBack({ 736,153,24,10 });
	fly.PushBack({ 761,152,24,12 });
	fly.PushBack({ 786,151,24,14 });
	fly.PushBack({ 811,152,24,12 });
	fly.PushBack({ 836,153,24,10 });
	fly.PushBack({ 811,152,24,12 });
	fly.PushBack({ 786,151,24,14 });
	fly.PushBack({ 761,152,24,12 });

	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 12 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_WhiteYellow::Move()
{

	position.x -= 1;

}

void Enemy_WhiteYellow::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}
