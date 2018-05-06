#include "Application.h"
#include "Enemy_GreenTurret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_GreenTurret::Enemy_GreenTurret(int x, int y) : Enemy(x, y)
{
	//lookingright.PushBack({ 430,0,39,29 });

	lookingleft.PushBack({ 523,0,44,29 });
	lookingleft.PushBack({ 523,0,44,29 });
	lookingleft.PushBack({ 523,0,44,29 });
	lookingleft.PushBack({ 523,0,44,29 });
	lookingleft.PushBack({ 569,0,46,29 });
	lookingleft.PushBack({ 615,0,48,29 });
	lookingleft.PushBack({ 665,0,47,29 });
	lookingleft.PushBack({ 713,0,49,29 });
	lookingleft.PushBack({ 521,33,49,29 });
	lookingleft.PushBack({ 571,33,51,29 });
	lookingleft.PushBack({ 623,33,46,29 });
	lookingleft.PushBack({ 713,0,49,29 });
	lookingleft.PushBack({ 665,0,47,29 });
	lookingleft.PushBack({ 569,0,46,29 });
	lookingleft.speed = 0.05666f;
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
		if (bullet == 16) {
			bullet = 0;
			App->particles->AddParticle(App->particles->laserenemygreenturret, position.x + 3, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		}
	}

}

void Enemy_GreenTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	
}
