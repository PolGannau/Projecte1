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

	path.PushBack({ -0.3f, 0.0f }, 70); //avança recte cap a la esquerre
	path.PushBack({ -0.7f, -0.5f }, 40); //puja adalt esquerre
	path.PushBack({ 1.0f, 0.0f }, 25); //avança recte cap a la dreta
	path.PushBack({ -0.8f, 0.0f }, 600); //avança recte cap a la esquerre
	


	collider = App->collision->AddCollider({ 0, 0, 31, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_WhiteShip::Move()
{
	position = original_pos + path.GetCurrentSpeed();

	timing++;

	if (timing == 160) {
		App->particles->AddParticle(App->particles->laserenemyup, position.x + 8, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->laserenemyleft, position.x + 8, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->laserenemydown, position.x + 8, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		timing = 0;
	}
}
void Enemy_WhiteShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}