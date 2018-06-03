#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	explosion.anim.PushBack({ 135, 26, 8, 7 });
	explosion.anim.PushBack({ 145, 20, 13, 13 });
	explosion.anim.PushBack({ 161, 9, 25, 24 });
	explosion.anim.PushBack({ 191, 8, 27, 26 });
	explosion.anim.PushBack({ 221, 5, 30, 29 });
	explosion.anim.PushBack({ 135, 41, 29, 28 });
	explosion.anim.PushBack({ 168, 41, 29, 28 });
	explosion.anim.PushBack({ 201, 42, 28, 28 });
	explosion.anim.PushBack({ 231, 44, 29, 27 });
	explosion.anim.PushBack({ 135, 76, 29, 27 });
	explosion.anim.PushBack({ 168, 78, 28, 26 });
	explosion.anim.PushBack({ 201, 79, 26, 24 });
	explosion.anim.PushBack({ 231, 81, 20, 21 });
	explosion.anim.PushBack({ 141, 109, 17, 17 });
	explosion.anim.PushBack({ 168, 117, 6, 6 });
	explosion.anim.loop = false;
	explosion.anim.speed = 0.3f;

	explosion2.anim.PushBack({ 250, 132, 4, 4 });
	explosion2.anim.PushBack({ 257, 124, 12, 12 });
	explosion2.anim.PushBack({ 273, 104, 32, 32 });
	explosion2.anim.PushBack({ 308, 105, 30, 30 });
	explosion2.anim.PushBack({ 342, 106, 30, 30 });
	explosion2.anim.PushBack({ 263, 144, 30, 30 });
	explosion2.anim.PushBack({ 297, 145, 30, 30 });
	explosion2.anim.PushBack({ 332, 143, 32, 32 });
	explosion2.anim.PushBack({ 269, 179, 32, 32 });
	explosion2.anim.PushBack({ 316, 180, 32, 32 });
	explosion2.anim.loop = false;
	explosion2.anim.speed = 0.2f;

	smallexplosion.anim.PushBack({ 385, 141, 6, 6 });
	smallexplosion.anim.PushBack({ 397, 139, 10, 8 });
	smallexplosion.anim.PushBack({ 411, 131, 16, 16 });
	smallexplosion.anim.PushBack({ 433, 133, 14, 14 });
	smallexplosion.anim.loop = false;
	smallexplosion.anim.speed = 0.13f;

	explosionship.anim.PushBack({ 48,153,27,17 });
	explosionship.anim.PushBack({ 85,152,28,18 });
	explosionship.anim.PushBack({ 123,149,30,21 });
	explosionship.anim.PushBack({ 163,145,31,25 });
	explosionship.anim.PushBack({ 48,181,33,27 });
	explosionship.anim.PushBack({ 90,177,32,31 });
	explosionship.anim.PushBack({ 132,175,32,32 });
	explosionship.anim.PushBack({ 48,213,30,30 });
	explosionship.anim.PushBack({ 90,223,28,20 });
	explosionship.anim.PushBack({ 130,228,24,15 });
	explosionship.anim.PushBack({ 166,232,19,11 });
	explosionship.anim.PushBack({ 197,234,15,9 });
	explosionship.anim.PushBack({ 48,250,17,13 });
	explosionship.anim.PushBack({ 77,248,15,15 });
	explosionship.anim.PushBack({ 113,255,7,3 });
	explosionship.anim.PushBack({ 143,257,2,1 });
	explosionship.anim.loop = false;
	explosionship.anim.speed = 0.3f;

	explosionship2.anim.PushBack({ 48,270,27,17 });
	explosionship2.anim.PushBack({ 85,269,28,18 });
	explosionship2.anim.PushBack({ 123,266,30,21 });
	explosionship2.anim.PushBack({ 163,262,31,25 });
	explosionship2.anim.PushBack({ 48,296,32,27 });
	explosionship2.anim.PushBack({ 90,292,32,31 });
	explosionship2.anim.PushBack({ 132,292,32,32 });
	explosionship2.anim.PushBack({ 48,213,30,30 });
	explosionship2.anim.PushBack({ 90,223,28,20 });
	explosionship2.anim.PushBack({ 130,228,24,15 });
	explosionship2.anim.PushBack({ 166,232,19,11 });
	explosionship2.anim.PushBack({ 197,234,15,9 });
	explosionship2.anim.PushBack({ 48,250,17,13 });
	explosionship2.anim.PushBack({ 77,248,15,15 });
	explosionship2.anim.PushBack({ 113,255,7,3 });
	explosionship2.anim.PushBack({ 143,257,2,1 });
	explosionship2.anim.loop = false;
	explosionship2.anim.speed = 0.3f;

	laser.anim.PushBack({ 26, 41, 11, 4 });
	laser.anim.speed = 0.2f;
	laser.speed.x = BULLET_SPEED;
	laser.life = BULLET_LIFE;

	BlueLaserPlayer.anim.PushBack({ 24, 53, 15, 6 });
	BlueLaserPlayer.anim.speed = 0.2f;
	BlueLaserPlayer.speed.x = BULLET_SPEED;
	BlueLaserPlayer.life = BULLET_LIFE;

	laser2right.anim.PushBack({ 8, 71, 10, 3 });
	laser2right.anim.speed = 0.2f;
	laser2right.speed.x = BULLET_SPEED;
	laser2right.life = BULLET_LIFE;

	laser2left.anim.PushBack({ 8, 86, 10, 3 });
	laser2left.anim.speed = 0.2f;
	laser2left.speed.x = -BULLET_SPEED;
	laser2left.life = BULLET_LIFE;

	
	Laser2PowerupBlue2up.anim.PushBack({ 7, 39, 11, 8 });
	Laser2PowerupBlue2up.speed.x = -BULLET_SPEED;
	Laser2PowerupBlue2up.speed.y = BULLET_SPEED / 3;
	Laser2PowerupBlue2up.life = BULLET_LIFE;

	Laser2PowerupBlue2down.anim.PushBack({ 7, 52, 11, 8 });
	Laser2PowerupBlue2down.speed.x = -BULLET_SPEED;
	Laser2PowerupBlue2down.speed.y = -BULLET_SPEED / 3;
	Laser2PowerupBlue2down.life = BULLET_LIFE;
	
	laser3.anim.PushBack({ 42, 94, 32, 3 });
	laser3.anim.speed = 0.2f;
	laser3.speed.x = BULLET_SPEED;
	laser3.life = BULLET_LIFE;

	laser4up.anim.PushBack({ 43, 13, 13, 2 });
	laser4up.anim.PushBack({ 43, 25, 13, 6 });
	laser4up.anim.PushBack({ 43, 40, 13, 7 });
	laser4up.anim.loop = false;
	laser4up.anim.speed = 0.2f;
	laser4up.speed.x = BULLET_SPEED;
	laser4up.speed.y = BULLET_SPEED/6;
	laser4up.life = BULLET_LIFE;

	laser4down.anim.PushBack({ 43, 13, 13, 2 });
	laser4down.anim.PushBack({ 43, 25, 13, 6 });
	laser4down.anim.PushBack({ 43, 40, 13, 7 });
	laser4down.anim.loop = false;
	laser4down.anim.speed = 0.2f;
	laser4down.speed.x = BULLET_SPEED;
	laser4down.speed.y = -BULLET_SPEED/6;
	laser4down.life = BULLET_LIFE; 

	laser4powerupblue.anim.PushBack({ 43, 13, 13, 2 });
	laser4powerupblue.anim.PushBack({ 43, 25, 13, 6 });
	laser4powerupblue.anim.PushBack({ 43, 40, 13, 7 });
	laser4powerupblue.anim.loop = false;
	laser4powerupblue.anim.speed = 0.2f;
	laser4powerupblue.speed.x = BULLET_SPEED;
	laser4powerupblue.life = BULLET_LIFE;

	laser4powerupredup.anim.PushBack({ 67, 15, 3, 16 });
	laser4powerupredup.anim.speed = 0.2f;
	laser4powerupredup.speed.y = -BULLET_SPEED;
	laser4powerupredup.speed.x += 1;
	laser4powerupredup.life = BULLET_LIFE;

	laser4powerupreddown.anim.PushBack({ 67, 15, 3, 16 });
	laser4powerupreddown.anim.speed = 0.2f;
	laser4powerupreddown.speed.y = BULLET_SPEED;
	laser4powerupreddown.speed.x +=1;
	laser4powerupreddown.life = BULLET_LIFE;

	laser2powerupred.anim.PushBack({ 389, 2, 9, 6 });
	laser2powerupred.anim.PushBack({ 388, 15, 10, 8 });
	laser2powerupred.anim.PushBack({ 387, 32, 13, 6 });
	laser2powerupred.anim.PushBack({ 386, 44, 15, 8 });
	laser2powerupred.anim.PushBack({ 385, 60, 16, 9 });
	laser2powerupred.anim.PushBack({ 386, 75, 14, 9 });
	laser2powerupred.anim.PushBack({ 385, 90, 16, 9 });
	laser2powerupred.anim.PushBack({ 386, 104, 15, 9 });
	laser2powerupred.anim.loop = false;
	laser2powerupred.anim.speed = 0.3f;
	laser2powerupred.speed.y = BULLET_SPEED;
	laser2powerupred.speed.x += 1;
	laser2powerupred.life = BULLET_LIFE;

	laser3powerupred.anim.PushBack({ 503, 15, 8, 9 });
	laser3powerupred.anim.loop = false;
	laser2powerupred.anim.speed = 0.3f;
	laser3powerupred.speed.y = BULLET_SPEED;
	laser3powerupred.speed.x += 1;
	laser3powerupred.life = BULLET_LIFE;

	laser1powerupred.anim.PushBack({ 415, 31, 10, 5 });
	laser1powerupred.anim.PushBack({ 413, 46, 13, 5 });
	laser1powerupred.anim.PushBack({ 415, 1, 10, 8 });
	laser1powerupred.anim.PushBack({ 414, 15, 12, 9 });
	laser1powerupred.anim.loop = false;
	laser1powerupred.anim.speed = 0.3f;
	laser1powerupred.speed.y = BULLET_SPEED;
	laser1powerupred.speed.x += 1;
	laser1powerupred.life = BULLET_LIFE;

	laserenemyup.anim.PushBack({238,244,8,8});
	laserenemyup.anim.PushBack({ 258,244,8,8 });
	laserenemyup.anim.PushBack({ 238,263,8,8 });
	laserenemyup.anim.PushBack({ 258,264,8,8 });
	laserenemyup.anim.speed = 0.2f;
	laserenemyup.anim.loop = true;
	laserenemyup.speed.x = -1.5f;
	laserenemyup.speed.y = -0.5f;
	laserenemyup.life = 5000;

	laserenemydown.anim.PushBack({ 238,244,8,8 });
	laserenemydown.anim.PushBack({ 258,244,8,8 });
	laserenemydown.anim.PushBack({ 238,264,8,8 });
	laserenemydown.anim.PushBack({ 258,264,8,8 });
	laserenemydown.anim.speed = 0.2f;
	laserenemydown.anim.loop = true;
	laserenemydown.speed.x = -1.5f;
	laserenemydown.speed.y = 0.5f;
	laserenemydown.life = 5000;

	laserenemyleft.anim.PushBack({ 238,244,8,8 });
	laserenemyleft.anim.PushBack({ 258,244,8,8 });
	laserenemyleft.anim.PushBack({ 238,245,8,8 });
	laserenemyleft.anim.PushBack({ 258,245,8,8 });
	laserenemyleft.anim.speed = 0.2f;
	laserenemyleft.anim.loop = true;
	laserenemyleft.speed.x = -1.5f;
	laserenemyleft.life = 5000;
	
	laserenemygreenturret.anim.PushBack({ 208,184,16,3 });
	laserenemygreenturret.anim.speed = 0.05f;
	laserenemygreenturret.speed.x = -BULLET_ENEMY_SPEED;
	laserenemygreenturret.speed.y = 0.3f;
	laserenemygreenturret.life = BULLET_ENEMY_LIFE;

	laserenemygreenturret2.anim.PushBack({ 208,184,16,3 });
	laserenemygreenturret2.anim.speed = 0.05f;
	laserenemygreenturret2.speed.x = BULLET_ENEMY_SPEED;
	laserenemygreenturret2.speed.y = 0.3f;
	laserenemygreenturret2.life = BULLET_ENEMY_LIFE;

	bullettouchgreenturret.anim.PushBack({ 650,17,44,29 });
	bullettouchgreenturret.anim.speed = 0.2f;
	
	GreenTurretExplosion.anim.PushBack({ 552,22,44,29 });
	GreenTurretExplosion.life = 8000;

	bullettouchgreenturret2.anim.PushBack({ 553,71,44,29 });
	bullettouchgreenturret2.anim.speed = 0.2f;

	GreenTurretExplosion2.anim.PushBack({ 652,76,44,29 });
	GreenTurretExplosion2.life = 8000;

	Structuretouch.anim.PushBack({ 5,341,48,136 });
	Structuretouch.anim.speed = 0.2f;
	Structuretouch.speed.y -= 1;

	Structuretouch1.anim.PushBack({ 5,341,48,136 });
	Structuretouch1.anim.speed = 0.2f;


	Structuredead.anim.PushBack({ 76,357,48,120 });
	Structuredead.speed.y = 0.5;
	Structuredead.life = 8000;

	Structuretouch2.anim.PushBack({ 167,341,48,136 });
	Structuretouch2.anim.speed = 0.2f;
	Structuretouch2.speed.y += 1;

	Structuretouch21.anim.PushBack({ 167,341,48,136 });
	Structuretouch21.anim.speed = 0.2f;

	Structuredead2.anim.PushBack({ 236,357,48,120 });
	Structuredead2.speed.y = -0.5;
	Structuredead2.life = 8000;


	followlaser.anim.PushBack({ 238,244,8,8 });
	followlaser.anim.PushBack({ 258,244,8,8 });
	followlaser.anim.PushBack({ 238,245,8,8 });
	followlaser.anim.PushBack({ 258,245,8,8 });
	followlaser.anim.speed = 0.2f;
	followlaser.anim.loop = true;
	followlaser.life = BULLET_ENEMY_LIFE;

	TurretShot1d.anim.PushBack({ 283,255,6,6 });
	TurretShot1d.anim.PushBack({ 293,255,6,6 });
	TurretShot1d.anim.PushBack({ 303,255,6,6 });
	TurretShot1d.anim.PushBack({ 313,255,6,6 });
	TurretShot1d.anim.speed = 0.1f;
	TurretShot1d.speed.x -= 2;
	TurretShot1d.life = BULLET_ENEMY_LIFE;

	TurretShot2d.anim.PushBack({ 283,255,6,6 });
	TurretShot2d.anim.PushBack({ 293,255,6,6 });
	TurretShot2d.anim.PushBack({ 303,255,6,6 });
	TurretShot2d.anim.PushBack({ 313,255,6,6 });
	TurretShot2d.anim.speed = 0.1f;
	TurretShot2d.speed.x -= 2;
	TurretShot2d.speed.y += 1;
	TurretShot2d.life = BULLET_ENEMY_LIFE;

	TurretShot3d.anim.PushBack({ 283,255,6,6 });
	TurretShot3d.anim.PushBack({ 293,255,6,6 });
	TurretShot3d.anim.PushBack({ 303,255,6,6 });
	TurretShot3d.anim.PushBack({ 313,255,6,6 });
	TurretShot3d.anim.speed = 0.1f;
	TurretShot3d.speed.x -= 2;
	TurretShot3d.speed.y += 2;
	TurretShot3d.life = BULLET_ENEMY_LIFE;

	TurretShot4d.anim.PushBack({ 283,255,6,6 });
	TurretShot4d.anim.PushBack({ 293,255,6,6 });
	TurretShot4d.anim.PushBack({ 303,255,6,6 });
	TurretShot4d.anim.PushBack({ 313,255,6,6 });
	TurretShot4d.anim.speed = 0.1f;
	TurretShot4d.speed.x -= 1;
	TurretShot4d.speed.y += 2;
	TurretShot4d.life = BULLET_ENEMY_LIFE;

	TurretShot5d.anim.PushBack({ 283,255,6,6 });
	TurretShot5d.anim.PushBack({ 293,255,6,6 });
	TurretShot5d.anim.PushBack({ 303,255,6,6 });
	TurretShot5d.anim.PushBack({ 313,255,6,6 });
	TurretShot5d.anim.speed = 0.1f;
	TurretShot5d.speed.y += 2;
	TurretShot5d.life = BULLET_ENEMY_LIFE;

	TurretShot6d.anim.PushBack({ 283,255,6,6 });
	TurretShot6d.anim.PushBack({ 293,255,6,6 });
	TurretShot6d.anim.PushBack({ 303,255,6,6 });
	TurretShot6d.anim.PushBack({ 313,255,6,6 });
	TurretShot6d.anim.speed = 0.1f;
	TurretShot6d.speed.x += 1;
	TurretShot6d.speed.y += 2;
	TurretShot6d.life = BULLET_ENEMY_LIFE;

	TurretShot7d.anim.PushBack({ 283,255,6,6 });
	TurretShot7d.anim.PushBack({ 293,255,6,6 });
	TurretShot7d.anim.PushBack({ 303,255,6,6 });
	TurretShot7d.anim.PushBack({ 313,255,6,6 });
	TurretShot7d.anim.speed = 0.1f;
	TurretShot7d.speed.x += 2;
	TurretShot7d.speed.y += 2;
	TurretShot7d.life = BULLET_ENEMY_LIFE;

	TurretShot8d.anim.PushBack({ 283,255,6,6 });
	TurretShot8d.anim.PushBack({ 293,255,6,6 });
	TurretShot8d.anim.PushBack({ 303,255,6,6 });
	TurretShot8d.anim.PushBack({ 313,255,6,6 });
	TurretShot8d.anim.speed = 0.1f;
	TurretShot8d.speed.x += 2;
	TurretShot8d.speed.y += 1;
	TurretShot8d.life = BULLET_ENEMY_LIFE;

	TurretShot9d.anim.PushBack({ 283,255,6,6 });
	TurretShot9d.anim.PushBack({ 293,255,6,6 });
	TurretShot9d.anim.PushBack({ 303,255,6,6 });
	TurretShot9d.anim.PushBack({ 313,255,6,6 });
	TurretShot9d.anim.speed = 0.1f;
	TurretShot9d.speed.x += 2;
	TurretShot9d.life = BULLET_ENEMY_LIFE;

	TurretShot1u.anim.PushBack({ 283,255,6,6 });
	TurretShot1u.anim.PushBack({ 293,255,6,6 });
	TurretShot1u.anim.PushBack({ 303,255,6,6 });
	TurretShot1u.anim.PushBack({ 313,255,6,6 });
	TurretShot1u.anim.speed = 0.1f;
	TurretShot1u.speed.x -= 2;
	TurretShot1u.life = BULLET_ENEMY_LIFE;

	TurretShot2u.anim.PushBack({ 283,255,6,6 });
	TurretShot2u.anim.PushBack({ 293,255,6,6 });
	TurretShot2u.anim.PushBack({ 303,255,6,6 });
	TurretShot2u.anim.PushBack({ 313,255,6,6 });
	TurretShot2u.anim.speed = 0.1f;
	TurretShot2u.speed.x -= 2;
	TurretShot2u.speed.y -= 1;
	TurretShot2u.life = BULLET_ENEMY_LIFE;

	TurretShot3u.anim.PushBack({ 283,255,6,6 });
	TurretShot3u.anim.PushBack({ 293,255,6,6 });
	TurretShot3u.anim.PushBack({ 303,255,6,6 });
	TurretShot3u.anim.PushBack({ 313,255,6,6 });
	TurretShot3u.anim.speed = 0.1f;
	TurretShot3u.speed.x -= 2;
	TurretShot3u.speed.y -= 2;
	TurretShot3u.life = BULLET_ENEMY_LIFE;

	TurretShot4u.anim.PushBack({ 283,255,6,6 });
	TurretShot4u.anim.PushBack({ 293,255,6,6 });
	TurretShot4u.anim.PushBack({ 303,255,6,6 });
	TurretShot4u.anim.PushBack({ 313,255,6,6 });
	TurretShot4u.anim.speed = 0.1f;
	TurretShot4u.speed.x -= 1;
	TurretShot4u.speed.y -= 2;
	TurretShot4u.life = BULLET_ENEMY_LIFE;

	TurretShot5u.anim.PushBack({ 283,255,6,6 });
	TurretShot5u.anim.PushBack({ 293,255,6,6 });
	TurretShot5u.anim.PushBack({ 303,255,6,6 });
	TurretShot5u.anim.PushBack({ 313,255,6,6 });
	TurretShot5u.anim.speed = 0.1f;
	TurretShot5u.speed.y -= 2;
	TurretShot5u.life = BULLET_ENEMY_LIFE;

	TurretShot6u.anim.PushBack({ 283,255,6,6 });
	TurretShot6u.anim.PushBack({ 293,255,6,6 });
	TurretShot6u.anim.PushBack({ 303,255,6,6 });
	TurretShot6u.anim.PushBack({ 313,255,6,6 });
	TurretShot6u.anim.speed = 0.1f;
	TurretShot6u.speed.x += 1;
	TurretShot6u.speed.y -= 2;
	TurretShot6u.life = BULLET_ENEMY_LIFE;

	TurretShot7u.anim.PushBack({ 283,255,6,6 });
	TurretShot7u.anim.PushBack({ 293,255,6,6 });
	TurretShot7u.anim.PushBack({ 303,255,6,6 });
	TurretShot7u.anim.PushBack({ 313,255,6,6 });
	TurretShot7u.anim.speed = 0.1f;
	TurretShot7u.speed.x += 2;
	TurretShot7u.speed.y -= 2;
	TurretShot7u.life = BULLET_ENEMY_LIFE;

	TurretShot8u.anim.PushBack({ 283,255,6,6 });
	TurretShot8u.anim.PushBack({ 293,255,6,6 });
	TurretShot8u.anim.PushBack({ 303,255,6,6 });
	TurretShot8u.anim.PushBack({ 313,255,6,6 });
	TurretShot8u.anim.speed = 0.1f;
	TurretShot8u.speed.x += 2;
	TurretShot8u.speed.y -= 1;
	TurretShot8u.life = BULLET_ENEMY_LIFE;

	TurretShot9u.anim.PushBack({ 283,255,6,6 });
	TurretShot9u.anim.PushBack({ 293,255,6,6 });
	TurretShot9u.anim.PushBack({ 303,255,6,6 });
	TurretShot9u.anim.PushBack({ 313,255,6,6 });
	TurretShot9u.anim.speed = 0.1f;
	TurretShot9u.speed.x += 2;
	TurretShot9u.life = BULLET_ENEMY_LIFE;

	Rocket.anim.PushBack({ 736,0,10,16 });
	Rocket.anim.PushBack({ 710,0,10,19 });
	Rocket.anim.PushBack({ 723,0,10,21 });
	Rocket.anim.speed = 0.1f;
	Rocket.speed.y -= 1;
	Rocket.life = BULLET_ENEMY_LIFE;


	Canonexplosion2.anim.PushBack({ 387, 174, 12, 19 });
	Canonexplosion2.anim.PushBack({ 273, 104, 32, 32 });
	Canonexplosion2.anim.PushBack({ 308, 105, 30, 30 });
	Canonexplosion2.anim.PushBack({ 342, 106, 30, 30 });
	Canonexplosion2.anim.PushBack({ 263, 144, 30, 30 });
	Canonexplosion2.anim.PushBack({ 297, 145, 30, 30 });
	Canonexplosion2.anim.PushBack({ 332, 143, 32, 32 });
	Canonexplosion2.anim.PushBack({ 269, 179, 32, 32 });
	Canonexplosion2.anim.PushBack({ 316, 180, 32, 32 });
	Canonexplosion2.anim.PushBack({ 387, 204, 16, 16 });
	Canonexplosion2.anim.loop = false;
	Canonexplosion2.anim.speed = 0.2f;
	Canonexplosion2.life = 900000;

	Canonattack.anim.PushBack({ 283,255,6,6 });
	Canonattack.anim.PushBack({ 293,255,6,6 });
	Canonattack.anim.PushBack({ 303,255,6,6 });
	Canonattack.anim.PushBack({ 313,255,6,6 });
	Canonattack.anim.speed = 0.1f;
	Canonattack.speed.y -= 1;
	Canonattack.life = BULLET_ENEMY_LIFE;

	triple.anim.PushBack({ 283,255,6,6 });
	triple.anim.PushBack({ 293,255,6,6 });
	triple.anim.PushBack({ 303,255,6,6 });
	triple.anim.PushBack({ 313,255,6,6 });
	triple.anim.speed = 0.1f;
	triple.speed.y -= 2;
	triple.life = BULLET_ENEMY_LIFE;

	tripled.anim.PushBack({ 283,255,6,6 });
	tripled.anim.PushBack({ 293,255,6,6 });
	tripled.anim.PushBack({ 303,255,6,6 });
	tripled.anim.PushBack({ 313,255,6,6 });
	tripled.anim.speed = 0.1f;
	tripled.speed.y -= 2;
	tripled.speed.x += 1;
	tripled.life = BULLET_ENEMY_LIFE;

	tripleu.anim.PushBack({ 283,255,6,6 });
	tripleu.anim.PushBack({ 293,255,6,6 });
	tripleu.anim.PushBack({ 303,255,6,6 });
	tripleu.anim.PushBack({ 313,255,6,6 });
	tripleu.anim.speed = 0.1f;
	tripleu.speed.y -= 2;
	tripleu.speed.x -= 1;
	tripleu.life = BULLET_ENEMY_LIFE;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/lasers_and_explosions.png");




	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	// Unload fx

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
				// play the audio SFX
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

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
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
	if (collider != nullptr) {
		collider->to_delete = true;
		collider = nullptr;
	}
	
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

