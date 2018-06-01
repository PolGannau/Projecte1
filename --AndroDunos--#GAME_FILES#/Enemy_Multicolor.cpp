#include "Application.h"
#include "Enemy_Multicolor.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"





Enemy_MultiColor::Enemy_MultiColor(int x, int y) : Enemy(x, y)
{
	type = MULTICOLOR;

	fly.PushBack({ 115, 329, 20, 20 });
	fly.PushBack({ 136, 329, 20, 20 });
	fly.PushBack({ 158, 329, 20, 20 });
	fly.PushBack({ 179, 329, 20, 21 });
	fly.PushBack({ 200, 329, 20, 20 });
	fly.PushBack({ 221, 329, 20, 21 });
	fly.PushBack({ 115, 350, 20, 20 });
	fly.PushBack({ 136, 350, 20, 20 });
	fly.PushBack({ 158, 350, 20, 20 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 20, 20 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_MultiColor::Move()
{
	position.x -= 1;


}

void Enemy_MultiColor::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}