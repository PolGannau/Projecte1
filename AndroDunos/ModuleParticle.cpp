#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/lasers_and_explosions.png");
	
	/*
	// Explosion particle
	explosion.anim.PushBack({ 4, 24, 8, 7 });
	explosion.anim.PushBack({ 14, 18, 13, 14 });
	explosion.anim.PushBack({ 30, 7, 25, 24 });
	explosion.anim.PushBack({ 60, 6, 27, 26 });
	explosion.anim.loop = false;
	explosion.anim.speed = 0.3f;
	*/
	laser.anim.PushBack({ 27, 41, 11, 4 });
	laser.anim.speed = 0.2f;
	laser.speed.x = 5;
	laser.life = 3000;

	laser2right.anim.PushBack({ 9, 72, 10, 3 });
	laser2right.anim.speed = 0.2f;
	laser2right.speed.x = 5;
	laser2right.life = 3000;

	laser2left.anim.PushBack({ 9, 87, 10, 3 });
	laser2left.anim.speed = 0.2f;
	laser2left.speed.x = -5;
	laser2left.life = 3000;

	laser3.anim.PushBack({ 59, 95, 16, 3 });
	laser3.anim.speed = 0.2f;
	laser3.speed.x = 5;
	laser3.life = 3000;

	laser4up.anim.PushBack({ 44, 14, 13, 2 });
	laser4up.anim.PushBack({ 44, 26, 13, 6 });
	laser4up.anim.PushBack({ 44, 41, 13, 7 });
	laser4up.anim.loop = false;
	laser4up.anim.speed = 0.2f;
	laser4up.speed.x = 5;
	laser4up.speed.y = 1;
	laser4up.life = 3000;

	laser4down.anim.PushBack({ 44, 14, 13, 2 });
	laser4down.anim.PushBack({ 44, 26, 13, 6 });
	laser4down.anim.PushBack({ 44, 41, 13, 7 });
	laser4down.anim.loop = false;
	laser4down.anim.speed = 0.2f;
	laser4down.speed.x = 5;
	laser4down.speed.y = -1;
	laser4down.life = 3000;
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

// TODO 5: Make so every time a particle hits a wall it triggers an explosion particle
void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

