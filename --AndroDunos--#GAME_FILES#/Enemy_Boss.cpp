#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "Stageclear.h"
#include "SDL/include/SDL_timer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	type = BOSS;

	/*nomove.PushBack({ 20, 650, 66, 224 });
	nomove.PushBack({ 128, 650, 66, 224 });
	nomove.PushBack({ 236, 650, 66, 224 });
	nomove.speed = 0.2f;
	//animation = &nomove;*/

	boss.PushBack({19,900,66,128});
	boss.PushBack({ 128,900,66,128 });
	boss.PushBack({ 236,900,66,128 });
	boss.speed = 0.1f;

	animation = &boss;

	path.PushBack({ 0.0f,-0.5f }, 60);
	path.PushBack({ 0.0f,0.0f }, 10);
	path.PushBack({ 0.0f,-0.5f }, 25);
	path.PushBack({ 0.0f,0.5f }, 60);
	path.PushBack({ 0.0f,0.0f }, 10);
	path.PushBack({ 0.0f,0.5f }, 25);

	collider = App->collision->AddCollider({ 0, 0, 66, 128 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}
void Enemy_Boss::Move()
{
	position = original_pos + path.GetCurrentSpeed();
	time++;
	if (time == 120) {
		App->particles->AddParticle(App->particles->boss, position.x - 23, position.y + 50);
		App->particles->AddParticle(App->particles->boss, position.x - 23, position.y + 75);
	}
	if (time == 180) {
		App->particles->AddParticle(App->particles->boss2, position.x, position.y + 60);
	}

	if (time == 185) {
		App->particles->AddParticle(App->particles->boss2, position.x, position.y + 60);
	}
	if (time == 190) {
		App->particles->AddParticle(App->particles->boss2, position.x, position.y + 60);
	}
	if (time == 195) {
		App->particles->AddParticle(App->particles->boss2, position.x, position.y + 60);
	}
	if (time == 200) {
		App->particles->AddParticle(App->particles->boss2, position.x, position.y + 60);
		time = 50;
	}
}
void Enemy_Boss::OnCollision(Collider* collider) 
{
	App->fade->FadeToBlack((Module*)App->stage2, (Module*)App->stageclear, 0.8f);
}
