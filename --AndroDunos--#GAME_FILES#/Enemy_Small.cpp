#include "Application.h"
#include "Enemy_Small.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL_timer.h"

Enemy_Small::Enemy_Small(int x, int y, int num) : Enemy(x, y)
{
	type = SMALL;

	if (num == 1) {
		fly.PushBack({ 540,191,16,10 });
		fly.PushBack({ 560,190,16,11 });
		fly.PushBack({ 581,189,16,13 });
		fly.PushBack({ 603,189,16,14 });
		fly.PushBack({ 623,189,16,13 });
		fly.PushBack({ 643,190,16,10 });
		fly.PushBack({ 540,208,16,10 });
		fly.PushBack({ 560,207,16,11 });
		fly.PushBack({ 581,206,16,13 });
		fly.PushBack({ 603,206,16,14 });
		fly.PushBack({ 623,206,16,13 });
		fly.PushBack({ 643,207,16,10 });

		fly.speed = 0.2f;

		animation = &fly;

		path.PushBack({ -1.0f, 1.0f }, 50);
		path.PushBack({ -1.0f, 0.7f }, 20);
		path.PushBack({ -1.0f,0.0f }, 2);
		path.PushBack({ -1.0f,-0.7f }, 10);
		path.PushBack({ -1.0f, -2.5f }, 5000);
	}
	else if (num == 2) {
		fly.PushBack({ 540,191,16,10 });
		fly.PushBack({ 560,190,16,11 });
		fly.PushBack({ 581,189,16,13 });
		fly.PushBack({ 603,189,16,14 });
		fly.PushBack({ 623,189,16,13 });
		fly.PushBack({ 643,190,16,10 });
		fly.PushBack({ 540,208,16,10 });
		fly.PushBack({ 560,207,16,11 });
		fly.PushBack({ 581,206,16,13 });
		fly.PushBack({ 603,206,16,14 });
		fly.PushBack({ 623,206,16,13 });
		fly.PushBack({ 643,207,16,10 });

		fly.speed = 0.2f;

		animation = &fly;

		path.PushBack({ 0.0f,-3.0f }, 40);
		path.PushBack({ 1.2f,-1.8f }, 15);
		path.PushBack({ 1.8f,-1.2f }, 15);
		path.PushBack({ 3.0f, 0.0f }, 12);
		path.PushBack({ 1.8f, 1.2f }, 15);
		path.PushBack({ 1.2f, 1.8f }, 15);
		path.PushBack({ 0.0f, 2.0f }, 12);
		path.PushBack({ -1.2f,1.8f }, 15);
		path.PushBack({ -1.8f,1.2f }, 15);
		path.PushBack({ -3.0f,0.0f }, 500);
	}
	else if (num == 3) {
		fly.PushBack({ 540,191,16,10 });
		fly.PushBack({ 560,190,16,11 });
		fly.PushBack({ 581,189,16,13 });
		fly.PushBack({ 603,189,16,14 });
		fly.PushBack({ 623,189,16,13 });
		fly.PushBack({ 643,190,16,10 });
		fly.PushBack({ 540,208,16,10 });
		fly.PushBack({ 560,207,16,11 });
		fly.PushBack({ 581,206,16,13 });
		fly.PushBack({ 603,206,16,14 });
		fly.PushBack({ 623,206,16,13 });
		fly.PushBack({ 643,207,16,10 });

		fly.speed = 0.2f;

		animation = &fly;

		path.PushBack({ -1.0f, -1.0f }, 50);
		path.PushBack({ -1.0f, -0.7f }, 20);
		path.PushBack({ -1.0f,0.0f }, 2);
		path.PushBack({ -1.0f,0.7f }, 10);
		path.PushBack({ -1.0f, 2.5f }, 5000);
	}
	collider = App->collision->AddCollider({ 0, 0, 16, 12 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Small::Move()
{
	position = original_pos + path.GetCurrentSpeed();


}
void Enemy_Small::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->smallexplosion, position.x, position.y);
}
