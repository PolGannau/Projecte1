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
	
	path.PushBack({ 0.4f, -0.0f }, 170); //avan�a recte cap a la esquerre
	path.PushBack({ -0.15f, 0.3f }, 40); //baixa  esquerre
	path.PushBack({ 0.3f, 0.0f }, 20); //pausa
	path.PushBack({ -0.15f, -0.3f }, 40); //puja  esquerre
	path.PushBack({ 1.5f, 0.0f }, 340); //endarrera
	path.PushBack({ 0.4f, -0.0f }, 100); //avan�a recte cap a la esquerre
	path.PushBack({ -0.15f, 0.3f }, 40); //baixa  esquerre
	path.PushBack({ 0.3f, 0.0f }, 20); //pausa
	path.PushBack({ -0.15f, -0.3f }, 40); //puja  esquerre
	path.PushBack({ 1.5f, 0.0f }, 340); //endarrera
	path.PushBack({ 0.4f, -0.0f }, 100); //avan�a recte cap a la esquerre
	path.PushBack({ -0.15f, 0.3f }, 40); //baixa  esquerre
	path.PushBack({ 0.3f, 0.0f }, 20); //pausa
	path.PushBack({ -0.15f, -0.3f }, 40); //puja  esquerre
	path.PushBack({ 1.5f, 0.0f }, 340); //endarrera
	path.PushBack({ 0.4f, -0.0f }, 100); //avan�a recte cap a la esquerre
	path.PushBack({ -0.15f, 0.3f }, 40); //baixa  esquerre
	path.PushBack({ 0.3f, 0.0f }, 20); //pausa
	path.PushBack({ -0.15f, -0.3f }, 40); //puja  esquerre
	path.PushBack({ 1.5f, 0.0f }, 340); //endarrera
	path.PushBack({ 0.7f, -0.0f }, 2000); //last one 

	/*path.PushBack({ -0.1f, 0.0f }, 60); //avan�a recte cap a la esquerre
	path.PushBack({ -0.4f, 0.2f }, 40); //baixa  esquerre
	path.PushBack({ 0.3f, 0.0f }, 20); //
	path.PushBack({ -0.4f, -0.2f }, 40); //puja  esquerre
	path.PushBack({ 1.5f, 0.0f }, 308); */

	original_pos.x = x;
	original_pos.y = y;
}

void ShipPowerUp::Move()
{
	position = original_pos + path.GetCurrentSpeed();
	position.x += 1;
}

void ShipPowerUp::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->powerups->AddPowerUp(POWERUPS_TYPES::POWERUPRED, position.x, position.y);

}