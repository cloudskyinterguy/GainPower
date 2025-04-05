#include "collision_manager.h"

#include<graphics.h>

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager* CollisionManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CollisionManager();
	}
	return instance;
}

CollisionManager::CollisionManager() = default;
CollisionManager::~CollisionManager() = default;

CollisionBox* CollisionManager::createCollisionBox()
{
	CollisionBox* box = new CollisionBox();
	collision_box_list.push_back(box);
	return box;
}

void CollisionManager::destoryCollisionBox(CollisionBox* box)
{
	//Âß¼­ÔÚ5:32
}

void CollisionManager::process_collide() {
	for (CollisionBox* box_src : collision_box_list)
	{
		if (!box_src->enabled || box_src->layer_dst == CollisionLayer::None)
		{
			continue;
		}

		for (CollisionBox* box_dst : collision_box_list)
		{
			if (!box_dst->enabled || box_dst == box_src || box_dst->layer_dst != box_src->layer_src)
			{
				continue;
			}
			//ÕâÀïÅÐ¶ÏÅö×²
			box_dst->on_collide();
		}
	}
}