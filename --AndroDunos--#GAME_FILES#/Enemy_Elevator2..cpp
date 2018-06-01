#include "Application.h"
#include "Enemy_Elevator2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Elevator2::Enemy_Elevator2(int x, int y) : Enemy(x, y)
{
	type = ELEVATOR2;

	elevator.PushBack({ 1598, 193, 224, 31 });
	elevator.PushBack({ 1598, 430, 224, 31 });
	elevator.PushBack({ 1598, 683, 224, 31 });
	elevator.PushBack({ 1598, 941, 224, 31 });
	elevator.speed = 0.02f;
	animation = &elevator;

	collider = App->collision->AddCollider({ 0, 0, 224, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_Elevator2::Move()
{

}
void Enemy_Elevator2::OnCollision(Collider* collider) {

}
