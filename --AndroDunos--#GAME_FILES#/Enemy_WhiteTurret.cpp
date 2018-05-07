#include "Application.h"
#include "Enemy_WhiteTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"


Enemy_WhiteTurret::Enemy_WhiteTurret(int x, int y) : Enemy(x, y)
{
	type = WHITETURRET;

	left.PushBack({ 156,50,15,14 });
	right.PushBack({ 176,67,15,14 });

	//if (leftt) {
		path.PushBack({ 0.0f, 0.0f }, 20, &left);
	//}
	//else if (rightt) {
		path.PushBack({ 0.0f, 0.0f }, 20, &right);
	//}

	

	collider = App->collision->AddCollider({ 0, 0, 15, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_WhiteTurret::Move() 
{
	position = original_pos + path.GetCurrentSpeed(&animation);

	/*if (App->player->position.x < position.x) {
		leftt = true;
		rightt = false;
	}
	else if (App->player->position.x > position.x) {
		rightt = true;
		leftt = false;
	}*/

}
void Enemy_WhiteTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}