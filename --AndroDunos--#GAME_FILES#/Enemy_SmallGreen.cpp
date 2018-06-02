#include "Application.h"
#include "Enemy_SmallGreen.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_SmallGreen::Enemy_SmallGreen(int x, int y) : Enemy(x, y)
{
	type = SMALLGREEN;

	fly.PushBack({ 116,382,16,16 });
	fly.PushBack({ 138,382,13,16 });
	fly.PushBack({ 155,382,11,16 });
	fly.PushBack({ 169,382,10,16 });
	fly.PushBack({ 184,382,11,16 });
	fly.PushBack({ 199,382,13,16 });
	fly.PushBack({ 217,382,16,16 });
	fly.speed = 0.05f;
	fly.loop = false;

	animation = &fly;

	path.PushBack({ 0.0f,-2.0f }, 50);
	path.PushBack({ 0.0f,0.0f }, 25);
	path.PushBack({ -2.0f,0.0f }, 35);
	path.PushBack({ -0.5f,0.0f }, 15);
	path.PushBack({ 0.0f,0.0f }, 2);
	path.PushBack({ 1.75f,0.0f }, 5);
	path.PushBack({ 3.5f,0.0f }, 500);
	collider = App->collision->AddCollider({ 0, 0, 16, 12 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_SmallGreen::Move()
{
	position = original_pos + path.GetCurrentSpeed();

}
void Enemy_SmallGreen::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}