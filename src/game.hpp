#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "level.h"
#include "hud.h"
#include "graphics.h"

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);


	Graphics _graphics;
};

#endif
