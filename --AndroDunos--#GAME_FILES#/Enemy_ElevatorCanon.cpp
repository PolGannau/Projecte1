#include "Application.h"
#include "Enemy_ElevatorCanon.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_ElevatorCanon::Enemy_ElevatorCanon(int x, int y, int num) : Enemy(x, y)
{
	type = ELEVATORCANON;
	
	appear.PushBack({ 565,0,16,16 });
	appear.PushBack({ 589,0,16,16 });
	appear.PushBack({ 613,0,16,16 });
	appear.PushBack({ 637,0,16,16 });
	appear.PushBack({ 661,0,16,16 });
	appear.PushBack({ 685,0,16,16 });
	appear.PushBack({ 709,0,16,16 });
	appear.speed = 0.2f;
	appear.loop = false;

	animation = &appear;

	disappear.PushBack({ 685,0,16,16 });
	disappear.PushBack({ 661,0,16,16 });
	disappear.PushBack({ 637,0,16,16 });
	disappear.PushBack({ 613,0,16,16 });
	disappear.PushBack({ 589,0,16,16 });
	disappear.PushBack({ 565,0,16,16 });
	disappear.PushBack({ 541,0,16,16 });
	disappear.speed = 0.1f;
	disappear.loop = false;
	this->num = num;
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_ElevatorCanon::Move()
{
	position.y += 1;
	if (num==1) {
		if (appear.SeeCurrentFrame() == 6) {
			++time;
		}
		if (appear.SeeCurrentFrame() == 6 && time>=150 && now) {
			App->particles->AddParticle(App->particles->Canonattack, position.x + 4, position.y);
			time = 0;
			now = false;
		}
		if (now == false) {
			++time;
		}
		if (now == false && time >= 300) {
			animation = &disappear;
		}
	}
	else if (num == 2) {
		if (appear.SeeCurrentFrame() == 6) {
			++time;
		}
		if (appear.SeeCurrentFrame() == 6 && time >= 75 && now) {
			App->particles->AddParticle(App->particles->Canonattack, position.x + 4, position.y);
			time = 0;
			now = false;
		}
		if (now == false) {
			++time;
		}
		if (now == false && time >= 150) {
			animation = &disappear;
		}
	}
}

void Enemy_ElevatorCanon::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->Canonexplosion2, position.x, position.y);
}