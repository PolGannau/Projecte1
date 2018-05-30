#include "Application.h"
#include "Enemy_Elevator.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Elevator::Enemy_Elevator(int x, int y) : Enemy(x, y)
{
	type = ELEVATOR;
	

	collider = App->collision->AddCollider({ 0, 0, 44, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_Elevator::Move()
{

}
void Enemy_Elevator::OnCollision(Collider* collider) {

}



