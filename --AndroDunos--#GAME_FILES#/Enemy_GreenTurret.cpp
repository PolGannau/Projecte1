#include "Application.h"
#include "Enemy_GreenTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_GreenTurret::Enemy_GreenTurret(int x, int y) : Enemy(x, y)
{
	type = GREENTURRET;

	//lookingright.PushBack({ 430,0,39,29 });

	lookingleft.PushBack({ 423,59,51,29 });
	lookingleft.PushBack({ 423,59,51,29 });
	lookingleft.PushBack({ 423,59,51,29 });
	lookingleft.PushBack({ 423,59,51,29 });
	lookingleft.PushBack({ 423,125,51,29 });
	lookingleft.PushBack({ 494,95,51,29 });
	lookingleft.PushBack({ 558,127,51,29 });
	lookingleft.PushBack({ 648,63,51,29 });
	lookingleft.PushBack({ 648,129,51,29 });
	lookingleft.PushBack({ 648,63,51,29 });
	lookingleft.PushBack({ 558,127,51,29 });
	lookingleft.PushBack({ 494,95,51,29 });
	lookingleft.PushBack({ 423,125,51,29 });
	
	lookingleft.speed = 0.15f;
	//animation = &lookingright;
	animation = &lookingleft;

	collider = App->collision->AddCollider({ 0, 0, 44, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_GreenTurret::Move()
{
	position.x -= 1;


	if (lookingleft.SeeCurrentFrame() == 8) {
		bullet++;
		if (bullet == 6) {
			App->particles->AddParticle(App->particles->laserenemygreenturret, position.x + 3, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		}
	}
	if (lookingleft.SeeCurrentFrame() == 9) {
		bullet = 0;
	}
	if (App->enemies->tocuh == true) {
		App->enemies->tocuh = false;
		App->particles->AddParticle(App->particles->bullettouchgreenturret, position.x, position.y);
	}
}





