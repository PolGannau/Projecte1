#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

class ModuleUi : public Module
{
public:

	ModuleUi();
	~ModuleUi();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * user_interface = nullptr;

	SDL_Rect credits_rect;
	SDL_Rect life1_rect;
	SDL_Rect life2_rect;

	Animation gameover;
	Animation* animationGameover = nullptr;

	Animation press1p;
	Animation* animationPress1p = nullptr;

	Animation press2p;
	Animation* animationPress2p = nullptr;

	int font_score = -1;
	char score_text[10];
	int font_score2 = -1;

	Uint32 score;

};

#endif //__MODULEUI_H__