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

	lookingleft.PushBack({ 523,0,39,29 });


	//animation = &lookingright;
	animation = &lookingleft;

	collider = App->collision->AddCollider({ 0, 0, 39, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}
void Enemy_GreenTurret::Move()
{
	position.x -= 1;

	timing++;

	if (timing == 80) {
		App->particles->AddParticle(App->particles->laserenemyfollow, position.x + 8, position.y + 7.5, COLLIDER_ENEMY_SHOT);
		timing = 0;
	}
}

void Enemy_GreenTurret::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	
}
