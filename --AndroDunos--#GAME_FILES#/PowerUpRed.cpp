#include "Application.h"
#include "PowerUpRed.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePowerUps.h"

PowerUpRed::PowerUpRed(int x, int y) : PowerUp(x, y)
{
	fly.PushBack({ 294,0,16,16 }); //start red
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 }); 
	//fly.PushBack({ 313,0,16,16 });
	fly.PushBack({ 331,0,16,16 });
	//fly.PushBack({ 349,0,16,16 });
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 });
	fly.PushBack({ 294,0,16,16 }); 
	fly.PushBack({ 367,0,16,16 });
	fly.PushBack({ 385,0,16,16 });  //last red
	fly.PushBack({ 329,36,16,16 }); //close doors
	fly.PushBack({ 294,18,16,16 }); //start blue
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 331,0,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 294,18,16,16 });
	fly.PushBack({ 367,18,16,16 });
	fly.PushBack({ 385,18,16,16 }); //last blue
	fly.PushBack({ 329,36,16,16 }); //close doors

	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_POWERUP, (Module*)App->powerups);

	original_y = y;
}

void PowerUpRed::Move()
{

	position.x -= 0.5;
}

void PowerUpRed::OnCollision(Collider* collider)
{
	if (fly.SeeCurrentFrame() == 1 || fly.SeeCurrentFrame() == 2 || fly.SeeCurrentFrame() == 3 || fly.SeeCurrentFrame() == 4 || fly.SeeCurrentFrame() == 5 || fly.SeeCurrentFrame() == 6 || fly.SeeCurrentFrame() == 7 || fly.SeeCurrentFrame() == 8 || fly.SeeCurrentFrame() == 9 || fly.SeeCurrentFrame() == 10 || fly.SeeCurrentFrame() == 11 || fly.SeeCurrentFrame() == 12 || fly.SeeCurrentFrame() == 13) {
		//App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 1050, 50);
		App->powerups->powerup1 = true;
	}
	else if (fly.SeeCurrentFrame() == 14 || fly.SeeCurrentFrame() == 15 || fly.SeeCurrentFrame() == 16 || fly.SeeCurrentFrame() == 17 || fly.SeeCurrentFrame() == 18 || fly.SeeCurrentFrame() == 19 || fly.SeeCurrentFrame() == 20 || fly.SeeCurrentFrame() == 21 || fly.SeeCurrentFrame() == 22 || fly.SeeCurrentFrame() == 23 || fly.SeeCurrentFrame() == 24 || fly.SeeCurrentFrame() == 25 || fly.SeeCurrentFrame() == 26) {
		//App->powerups->AddPowerUp(POWERUPS_TYPES::SHIPPOWERUP, 1050, 50);
		App->powerups->powerup2 = true;
	}
	
	
}
