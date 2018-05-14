#ifndef __ModulePowerUps_H__
#define __ModulePowerUps_H__

#include "Module.h"
#include "ShipPowerUp.h"
#include "PowerUpRed.h"

#define MAX_POWERUPS 15

enum POWERUPS_TYPES
{
	NON_TYPE,
	SHIPPOWERUP,
	POWERUPRED,
};

class PowerUp;

struct PowerUpInfo
{
	POWERUPS_TYPES type = POWERUPS_TYPES::NON_TYPE;
	int x, y;
};

class ModulePowerUps : public Module
{
public:

	ModulePowerUps();
	~ModulePowerUps();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	bool powerup1 = false, powerup2 = false, powerup3 = false, powerup4 = false;
	bool power2up1 = false, power2up2 = false, power2up3 = false, power2up4 = false;
	bool AddPowerUp(POWERUPS_TYPES type, int x, int y);

private:

	void SpawnPowerUp(const PowerUpInfo& info);

private:

	PowerUpInfo queue[MAX_POWERUPS];
	PowerUp* powerups[MAX_POWERUPS];
	SDL_Texture* sprites;
};

#endif
