#include "Application.h"
#include "Enemy_WhiteShip.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include <math.h>


Enemy_WhiteShip::Enemy_WhiteShip(int x, int y, int num) : Enemy(x, y)
{
	type = WHITESHIP;

	if (num == 1) {

		fly.PushBack({ 1,0,31,27 });
		fly.PushBack({ 32, 0, 31, 27 });

		fly.speed = 0.2f;

		animation = &fly;

		path.PushBack({ -0.5f, -0.3f }, 40); //puja adalt esquerre
		path.PushBack({ 1.0f, 0.0f }, 75); //avança recte cap a la dreta
		path.PushBack({ -0.3f, 0.0f }, 600); //avança recte cap a la esquerre

	}
	else if (num == 2) {

		fly.PushBack({ 1,0,31,27 });
		fly.PushBack({ 32, 0, 31, 27 });

		fly.speed = 0.2f;

		animation = &fly;

		path.PushBack({ -0.5f, 0.3f }, 40); //puja adalt esquerre
		path.PushBack({ 1.0f, 0.0f }, 75); //avança recte cap a la dreta
		path.PushBack({ -0.3f, 0.0f }, 600); //avança recte cap a la esquerre

	}

	collider = App->collision->AddCollider({ 0, 0, 31, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_WhiteShip::Move()
{
	position = original_pos + path.GetCurrentSpeed();

	timing++;

	if (timing == 125  || timing == 210) {
		//App->particles->AddParticle(App->particles->laserenemyup, position.x, position.y + 15, COLLIDER_ENEMY_SHOT);
		//App->particles->AddParticle(App->particles->laserenemyleft, position.x, position.y + 15, COLLIDER_ENEMY_SHOT);
		//App->particles->AddParticle(App->particles->laserenemydown, position.x, position.y + 15, COLLIDER_ENEMY_SHOT);
		x = App->player->position.x - position.x;
		y = App->player->position.y - position.y;
		m = sqrt((x*x) + (y*y));
		x = x / m;
		y = y / m;
		App->particles->followlaser.speed.x = x * 1.8f;
		App->particles->followlaser.speed.y = y * 1.8f;
		App->particles->AddParticle(App->particles->followlaser, position.x, position.y + 15, COLLIDER_ENEMY_SHOT);
	}
}
void Enemy_WhiteShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}