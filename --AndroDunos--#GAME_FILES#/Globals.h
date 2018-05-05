#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL\include\SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define TILE_WIDTH 251

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Useful typedefs ---------
typedef unsigned int uint;

// Configuration -----------
#define SCREEN_SIZE 1 // 1 full screen
#define SCREEN_WIDTH 304 // 304 full screen
#define SCREEN_HEIGHT 224 // 224 full screen
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 1 // 1 full screen
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0
#define REN_VSYNC 1

#endif // __GLOBALS_H__
