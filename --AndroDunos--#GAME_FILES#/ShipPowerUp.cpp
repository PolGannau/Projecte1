#include "Application.h"
#include "ShipPowerUp.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePowerUps.h"

ShipPowerUp::ShipPowerUp(int x, int y) : PowerUp(x, y)
{
	fly.PushBack({ 3,0,18,26 });
	fly.PushBack({ 29, 0, 18, 26 });
	fly.PushBack({ 55, 0, 18, 25 });
	fly.PushBack({ 81, 0, 18, 25 });
	fly.PushBack({ 106, 0, 20, 26 });
	fly.PushBack({ 133, 0, 18, 26 });
	fly.PushBack({ 159, 0, 18, 25 });
	fly.PushBack({ 185, 0, 18, 25 });
	fly.PushBack({ 211, 0, 18, 25 });
	fly.PushBack({ 237, 0, 20, 26 });
	fly.PushBack({ 262, 3, 21, 21 });
	fly.PushBack({ 0, 31, 24, 18 });
	fly.PushBack({ 25, 32, 26, 18 });
	fly.PushBack({ 52, 32, 25, 18 });
	fly.PushBack({ 78, 32, 25, 18 });
	fly.PushBack({ 106, 32, 21, 21 });
	fly.PushBack({ 131, 32, 21, 21 });
	fly.PushBack({ 160, 28, 18, 25 });
	fly.PushBack({ 185, 28, 18, 25 });
	fly.PushBack({ 211, 27, 18, 26 });
	fly.PushBack({ 237, 27, 18, 26 });
	fly.PushBack({ 237, 27, 18, 26 });
	fly.PushBack({ 3, 53, 18, 26 });
	fly.PushBack({ 29, 53, 18, 26 });
	fly.PushBack({ 53, 53, 18, 26 });
	fly.PushBack({ 82, 53, 18, 25 });
	fly.PushBack({ 104, 56, 19, 21 });
	fly.PushBack({ 129, 57, 25, 18 });
	fly.PushBack({ 155, 57, 26, 18 });
	fly.PushBack({ 181, 57, 26, 18 });
	fly.PushBack({ 208, 56, 25, 18 });
	fly.PushBack({ 234, 56, 25, 18 });
	fly.PushBack({ 263, 55, 20, 21 });
	fly.PushBack({ 2, 82, 21, 21 });
	fly.PushBack({ 29, 80, 18, 25 });
	fly.PushBack({ 55, 80, 18, 25 });
	fly.PushBack({ 81, 79, 18, 26 });
	fly.PushBack({ 107, 79, 18, 26 });
	fly.PushBack({ 133, 79, 18, 26 });
	fly.PushBack({ 159, 79, 18, 26 });
	fly.speed = 0.05f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 31, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->powerups);

	original_y = y;
}

void ShipPowerUp::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));
	position.x -= 1;

}

void ShipPowerUp::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->powerups->AddPowerUp(POWERUPS_TYPES::POWERUPRED, position.x, position.y);

}