#include "Application.h"
#include "Enemy_Ship.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Ship::Enemy_Ship(int x, int y) : Enemy(x, y)
{
	type = SHIP;


	fly.PushBack({ 1087,3,35,22 });
	fly.PushBack({ 1127,6,35,19 });
	fly.PushBack({ 1170,5,35,20 });
	fly.PushBack({ 1213,3,34,27 });
	fly.PushBack({ 1249,0,33,35 });
	fly.PushBack({ 1288,3,35,27 });
	fly.PushBack({ 1329,6,35,23 });
	fly.PushBack({ 1370,10,35,19 });
	fly.PushBack({ 1410,5,34,22 });
	fly.PushBack({ 1447,2,35,27 });
	fly.PushBack({ 1485,0,35,35 });
	fly.PushBack({ 1526,5,35,27 });

	fly.speed = 0.2f;


	animation = &fly;


	collider = App->collision->AddCollider({ 0, 0, 35, 25 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_Ship::Move()
{
	position.x -= 1;
}
void Enemy_Ship::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}
