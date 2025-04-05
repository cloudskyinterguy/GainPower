#pragma once

#include "collision_box.h"

#include <vector>

class CollisionManager
{
public:
	static CollisionManager* getInstance();

	CollisionBox* createCollisionBox();

	void destoryCollisionBox(CollisionBox* box);

	void process_collide();

	void debug_render();

private:

	static CollisionManager* instance;

	std::vector<CollisionBox*> collision_box_list;

private:
	CollisionManager();
	
	~CollisionManager();

private:

};
