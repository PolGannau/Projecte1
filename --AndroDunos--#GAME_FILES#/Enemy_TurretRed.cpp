#include "Application.h"
#include "Enemy_TurretRed.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "SDL/include/SDL_timer.h"

Enemy_TurretRed::Enemy_TurretRed(int x, int y) : Enemy(x, y)
{
	type = TURRETRED;


	left.PushBack({ 1088,190,24,22 });
	left.PushBack({ 1130,190,24,22 });
	left.PushBack({ 1172,190,24,22 });
	left.PushBack({ 1088,215,25,22 });
	left.PushBack({ 1131,215,24,22 });
	left.PushBack({ 1171,215,24,22 });
	left.PushBack({ 1086,245,24,22 });
	left.loop = false;
	left.speed = 0.05f;

	path.PushBack({ 0.0f,0.0f }, 1, &left);



	collider = App->collision->AddCollider({ 0, 0, 20, 306 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_TurretRed::Move()
{
	position = original_pos + path.GetCurrentSpeed(&animation);
}
void Enemy_TurretRed::OnCollision(Collider* collider) {

}