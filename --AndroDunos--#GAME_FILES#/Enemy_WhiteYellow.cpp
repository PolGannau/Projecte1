#include "Application.h"
#include "Enemy_WhiteYellow.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"

Enemy_WhiteYellow::Enemy_WhiteYellow(int x, int y, int mov) : Enemy(x, y)
{
	type = WHITEYELLOW;

	if (mov == 1) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,-1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 100);
		path.PushBack({ -2.5f, -0.4f }, 2000);
	}
	else if (mov == 2) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 100);
		path.PushBack({ -2.5f, 0.4f }, 2000);
	}
	else if (mov == 3) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,-1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 80);
		path.PushBack({ -2.5f, -0.4f }, 2000);
	}
	else if (mov == 4) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 80);
		path.PushBack({ -2.5f, 0.4f }, 2000);
	}
	else if (mov == 5) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,-1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 60);
		path.PushBack({ -2.5f, -0.4f }, 2000);
	}
	else if (mov == 6) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 60);
		path.PushBack({ -2.5f, 0.4f }, 2000);
	}
	else if (mov == 7) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,-1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 40);
		path.PushBack({ -2.5f, -0.4f }, 2000);
	}
	else if (mov == 8) {
		fly.PushBack({ 736,153,24,10 });
		fly.PushBack({ 761,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 836,153,24,10 });
		fly.PushBack({ 811,152,24,12 });
		fly.PushBack({ 786,151,24,14 });
		fly.PushBack({ 761,152,24,12 });

		fly.speed = 0.1f;

		animation = &fly;

		path.PushBack({ 0.6f,1.0f }, 80);
		path.PushBack({ 0.0f,0.0f }, 40);
		path.PushBack({ -2.5f, 0.4f }, 2000);
	}

	collider = App->collision->AddCollider({ 0, 0, 24, 12 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_WhiteYellow::Move()
{
	position = original_pos + path.GetCurrentSpeed();

}

void Enemy_WhiteYellow::OnCollision(Collider* collider) {
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
}
