#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define BULLET_LIFE 500

#define BULLET_SPEED 10
#define BULLET_ENEMY_SPEED 5

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture * graphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:

	Particle explosion;
	Particle explosion2;
	Collider* debug = nullptr;
	Particle explosionship;
	Particle explosionship2;
	Particle laser;
	Particle laser2right;
	Particle laser2left;
	Particle laser3;
	Particle laser4up;
	Particle laser4down;
	Particle powerup;
	Particle laser4powerupblue;
	Particle laser4powerupredup;
	Particle laser4powerupreddown;
	Particle laser1powerupred;
	Particle laser3powerupred;
	Particle laser2powerupred;
	Particle laserenemyup;
	Particle laserenemydown;
	Particle laserenemyleft;
	

};

#endif // __MODULEPARTICLES_H__