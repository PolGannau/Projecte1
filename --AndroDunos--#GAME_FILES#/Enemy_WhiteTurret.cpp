#include "Application.h"
#include "Enemy_WhiteTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"


Enemy_WhiteTurret::Enemy_WhiteTurret(int x, int y): Enemy(x, y)
{
	type = WHITETURRET;
	
	
	
	anim = 1;
	

	collider = App->collision->AddCollider({ 0, 0, 15, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	
}

void Enemy_WhiteTurret::Move() 
{
	position = original_pos + path.GetCurrentSpeed(&animation);
	if (anim == 1) {
		left.Sprite({ 156,50,15,14 });
		animation = &left;
	}
	else if (anim == 2) {
		right.Sprite({ 176,67,15,14 });
		animation = &right;
	}

	if (App->player->position.x < position.x) {
		anim = 1;
	}
	else if (App->player->position.x > position.x) {
		anim = 2;
	}
}
void Enemy_WhiteTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}