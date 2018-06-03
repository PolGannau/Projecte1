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
	fly.speed = 0.05f;

	fly.loop = false;


	fly.speed = 0.1f;

	animation = &fly;

	path.PushBack({ -1.0f, 1.0f }, 30);
	path.PushBack({ -1.0f,0.5f }, 15);
	path.PushBack({ -1.0f,0.0f }, 5);
	path.PushBack({ -1.0f,-0.5f }, 15);
	path.PushBack({ -1.0f,-1.0f }, 37);
	path.PushBack({ -0.5f,-0.5f }, 15);
	path.PushBack({ -0.5f,0.0f }, 5);
	path.PushBack({ -0.5f,0.5f }, 15);
	path.PushBack({ 0.0f,0.5f }, 15);
	path.PushBack({ 1.0f, 1.0f }, 10);
	path.PushBack({ 2.0f, 0.0f }, 500);
	collider = App->collision-> AddCollider({ 0, 0, 20, 20 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MultiColor::Move()
{
	position = original_pos + path.GetCurrentSpeed();

	if (fly.SeeCurrentFrame() == 19 && now) {
		x = App->player->position.x - position.x;
		y = App->player->position.y - position.y;
		m = sqrt((x*x) + (y*y));
		x = x / m;
		y = y / m;
		App->particles->followlaser.speed.x = x * 1.8f;
		App->particles->followlaser.speed.y = y * 1.8f;
		App->particles->AddParticle(App->particles->followlaser, position.x, position.y + 8, COLLIDER_ENEMY_SHOT);
		now = false;
	}


}

void Enemy_MultiColor::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}