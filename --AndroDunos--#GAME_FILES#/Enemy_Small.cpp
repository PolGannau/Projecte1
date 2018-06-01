#include "Application.h"
#include "Enemy_Small.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Small::Enemy_Small(int x, int y) : Enemy(x, y)
{
	type = SMALL;


	fly.PushBack({ 540,191,16,10 });
	fly.PushBack({ 560,190,16,11 });
	fly.PushBack({ 581,189,16,13 });
	fly.PushBack({ 603,189,16,14 });
	fly.PushBack({ 623,189,16,13 });
	fly.PushBack({ 643,190,16,10 });
	fly.PushBack({ 540,208,16,10 });
	fly.PushBack({ 560,207,16,11 });
	fly.PushBack({ 581,206,16,13 });
	fly.PushBack({ 603,206,16,14 });
	fly.PushBack({ 623,206,16,13 });
	fly.PushBack({ 643,207,16,10 });
	

	fly.speed = 0.2f;


	animation = &fly;


	collider = App->collision->AddCollider({ 0, 0, 35, 25 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_Small::Move()
{
	position.x -= 1;
}
void Enemy_Small::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}