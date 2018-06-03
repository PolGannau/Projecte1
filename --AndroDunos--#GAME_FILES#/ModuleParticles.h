#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define BULLET_LIFE 500
#define BULLET_ENEMY_LIFE 2000
#define BULLET_SPEED 10
#define BULLET_ENEMY_SPEED 2

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	fPoint position;
	fPoint speed;
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
	Particle smallexplosion;
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
	Particle laserenemygreenturret;
	Particle laserenemygreenturret2;
	Particle bullettouchgreenturret;
	Particle GreenTurretExplosion;
	Particle bullettouchgreenturret2;
	Particle GreenTurretExplosion2;
	Particle TurretShot;
	Particle Structuretouch;
	Particle Structuredead;
	Particle Structuretouch2;
	Particle Structuredead2;
	Particle followlaser;
	Particle Structuretouch1;
	Particle Structuretouch21;
	Particle BlueLaserPlayer;
	Particle Laser2PowerupBlue2up;
	Particle Laser2PowerupBlue2down;
	Particle TurretShot1d;
	Particle TurretShot2d;
	Particle TurretShot3d;
	Particle TurretShot4d;
	Particle TurretShot5d;
	Particle TurretShot6d;
	Particle TurretShot7d;
	Particle TurretShot8d;
	Particle TurretShot9d;
	Particle TurretShot1u;
	Particle TurretShot2u;
	Particle TurretShot3u;
	Particle TurretShot4u;
	Particle TurretShot5u;
	Particle TurretShot6u;
	Particle TurretShot7u;
	Particle TurretShot8u;
	Particle TurretShot9u;
	Particle Rocket;
	Particle Canonattack;
	Particle Canonexplosion2;
	Particle triple, tripleu, tripled;
	Particle SBlaser, SBlaseru, SBlaserd;
	Particle boss, boss2;

};

#endif // __MODULEPARTICLES_H__