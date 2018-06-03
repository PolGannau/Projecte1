#include "Application.h"
#include "Enemy_MiniBoss.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"
#include <math.h>  



Enemy_MiniBoss::Enemy_MiniBoss(int x, int y) : Enemy(x, y)
{
	type = MINIBOSS;

	fly.PushBack({ 965, 290, 79, 176 });


	fly.loop = false;


	fly.speed = 0.1f;

	animation = &fly;

	path.PushBack({ -0.5f, 0.0f }, 100);
	path.PushBack({ -1.0f, 0.0f }, 150);
	path.PushBack({ -3.0f, 0.0f }, 50);
	path.PushBack({ 1.5f, 0.0f }, 25);

	collider = App->collision->AddCollider({ 0, 0, 79, 176 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_MiniBoss::Move()
{
	position = original_pos + path.GetCurrentSpeed();
	if (go) {
		time++;
		time2++;
		if (time == 90) {
			x = App->player->position.x - position.x;
			y = App->player->position.y - position.y;
			m = sqrt((x*x) + (y*y));
			x = x / m;
			y = y / m;
			App->particles->followlaser.speed.x = x * 4.0f;
			App->particles->followlaser.speed.y = y * 4.0f;
			App->particles->AddParticle(App->particles->followlaser, position.x, position.y + 40, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->followlaser, position.x, position.y + 130, COLLIDER_ENEMY_SHOT);
			time = 0;
		}
		if (time2 == 320) {
			App->particles->AddParticle(App->particles->SBlaser, position.x, position.y + 90, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaseru, position.x, position.y + 70, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaserd, position.x, position.y + 110, COLLIDER_ENEMY_SHOT);
		}
		if (time2 == 325) {
			App->particles->AddParticle(App->particles->SBlaser, position.x, position.y + 90, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaseru, position.x, position.y + 70, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaserd, position.x, position.y + 110, COLLIDER_ENEMY_SHOT);
		}
		if (time2 == 370) {
			App->particles->AddParticle(App->particles->SBlaser, position.x, position.y + 90, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaseru, position.x, position.y + 70, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaserd, position.x, position.y + 110, COLLIDER_ENEMY_SHOT);

		}
		if (time2 == 375) {
			App->particles->AddParticle(App->particles->SBlaser, position.x, position.y + 90, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaseru, position.x, position.y + 70, COLLIDER_ENEMY_SHOT);
			App->particles->AddParticle(App->particles->SBlaserd, position.x, position.y + 110, COLLIDER_ENEMY_SHOT);
			time2 = 0;
		}

	}
	else if (go == false) {
		/*mov += 0.5f;
		if (mov == 1) {
			position.x -= 1;
			mov = 0;
		}*/
		if (position.x == 3761) {
			go = true;
			App->enemies->subBoss = true;
			mov = 0;
		}
	}


}

void Enemy_MiniBoss::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}