#include "Application.h"
#include "Enemy_StraightOnShip.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_StraightOnShip::Enemy_StraightOnShip(int x, int y, int num) : Enemy(x, y)
{
	type = STRAIGHTONSHIP;

	if (num==1) { //up
		fly.PushBack({ 187,1,29,13 });
		fly.PushBack({ 217, 0, 29, 16 });
		fly.PushBack({ 247, 1, 29, 17 });
		fly.PushBack({ 217, 0, 29, 16 });
		fly.PushBack({ 277, 1, 29, 14 });
		fly.speed = 0.1f;
		animation = &fly;

		path.PushBack({-2.0f,0.0f},37);
		path.PushBack({ 2.0f,-0.8f }, 25);
		path.PushBack({ -4.0f,0.0f }, 500);
		movement = 1;
	}
	else if (num == 2) { //straight on
		fly.PushBack({ 187,1,29,13 });
		fly.PushBack({ 217, 0, 29, 16 });
		fly.PushBack({ 247, 1, 29, 17 });
		fly.PushBack({ 217, 0, 29, 16 });
		fly.PushBack({ 277, 1, 29, 14 });
		fly.speed = 0.1f;
		animation = &fly;
		movement = 2;
	}


	collider = App->collision->AddCollider({ 0, 0, 29, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_StraightOnShip::Move()
{
	
	if (movement==1) {
		position = original_pos + path.GetCurrentSpeed();
	}
	else if (movement == 2) {
		position.x -= 1;
	}
}

void Enemy_StraightOnShip::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}