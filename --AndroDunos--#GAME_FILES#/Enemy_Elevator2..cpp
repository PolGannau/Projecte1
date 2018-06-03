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
	elevator.speed = 0.2f;
	animation = &elevator;

	path.PushBack({ 0.0f, -1.0f }, 399);
	path.PushBack({ 0.0f, 0.0f }, 160);
	path.PushBack({ 0.0f, 1.0f }, 1571);
	path.PushBack({ 0.0f, 0.0f }, 500000);

	collider = App->collision->AddCollider({ 0, 0, 224, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Elevator2::Move()
{
	position = original_pos + path.GetCurrentSpeed();
	++time;

	if (time == 890) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 160, position.y, false, 1);
	}
	if (time == 965) { //aqui apareix el primer dadalt posicio 5
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 112, position.y, false, 1);
	}
	if (time == 1040) { //aqui apareix el 2n i 3r dadalt posicio 2 i 6
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 192, position.y, false, 1);
	}
	if (time == 1500) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 128, position.y, false, 1);
	}
	if (time == 1515) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 16, position.y, false, 1);
	}
	if (time == 1545) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 78, position.y, false, 2);
	}
	if (time == 1575) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 158, position.y, false, 2);
	}
	if (time == 1605) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 48, position.y, false, 2);
	}
	if (time == 1635) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 80, position.y, false, 2);
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 144, position.y, false, 2);
	}
	if (time == 1655) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 32, position.y, false, 2);
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 96, position.y, false, 2);
	}
	if (time == 1685) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 208, position.y, false, 2);
	}
	if (time == 1685) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 144, position.y, false, 2);
	}
	if (time == 1700) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 16, position.y, false, 2);
	}
	if (time == 1730) {
		App->enemies->AddEnemy(ENEMY_TYPES::ELEVATORCANON, position.x + 48, position.y, false, 2);
	}
}
void Enemy_Elevator2::OnCollision(Collider* collider) {}
