#include "Application.h"
#include "Enemy_WhiteShip.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"


Enemy_WhiteShip::Enemy_WhiteShip(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 1,0,31,27 });
	fly.PushBack({ 32, 0, 31, 27 });

	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 31, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_WhiteShip::Move()
{
	position.x -= 1;
}
void Enemy_WhiteShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}