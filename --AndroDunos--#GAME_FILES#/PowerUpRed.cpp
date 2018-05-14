#include "Application.h"
#include "PowerUpRed.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePowerUps.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

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
	if (fly.SeeCurrentFrame() <= 13) {
		if (collider->type == COLLIDER_PLAYER)
		{
			App->powerups->powerup1 = true;
		}
		else if (collider->type == COLLIDER_PLAYER2)
		{
			App->powerups->power2up1 = true;
		}
	}
	else if (fly.SeeCurrentFrame() >= 14 && fly.SeeCurrentFrame() <= 26) {
		if (collider->type == COLLIDER_PLAYER)
		{
			App->powerups->powerup2 = true;
		}
		else if (collider->type == COLLIDER_PLAYER2)
		{
			App->powerups->power2up2 = true;
		}
	}


}
