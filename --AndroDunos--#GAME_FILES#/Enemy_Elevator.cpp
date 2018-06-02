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
	
	elevator.PushBack({ 1598, 0, 224, 47 });
	elevator.PushBack({ 1598, 237, 224, 47 });
	elevator.PushBack({ 1598, 490, 224, 47 });
	elevator.PushBack({ 1598, 748, 224, 47 });
	elevator.speed = 0.02f;
	animation = &elevator;

	path.PushBack({ 0.0f, 1.0f }, 400);
	path.PushBack({ 0.0f, 0.0f }, 160);
	path.PushBack({ 0.0f, 1.0f }, 1556);
	path.PushBack({ 0.0f, 0.0f }, 50000);
	collider = App->collision->AddCollider({ 0, 0, 224, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Elevator::Move()
{
	position = original_pos + path.GetCurrentSpeed();
	App->enemies->timeelevator++;
}
void Enemy_Elevator::OnCollision(Collider* collider) {

}



