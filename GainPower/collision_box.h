#pragma once

#include "Vector2.h"
#include "collisionlayer.h"

#include<functional>

class CollisionBox
{

	friend class CollisionManager;

private:
	CollisionBox() = default;
	~CollisionBox() = default;

private:
	Vector2 position;
	Vector2 size;
	
	CollisionLayer layer_src = CollisionLayer::None;
	CollisionLayer layer_dst = CollisionLayer::None;

	bool enabled = true;

	std::function<void()> on_collide;

public:
	void setPosition(const Vector2& pos) {
		this->position = pos;
	}

	//get方法

	void setSize(const Vector2& size) {
		this->size = size;
	}

	//get方法

	void setLayerSrc(CollisionLayer layer) {
		this->layer_src = layer;
	}

	void setLayerDst(CollisionLayer layer) {
		this->layer_dst = layer;
	}

	void setEnabled(bool enabled) {
		this->enabled = enabled;
	}

	void setOnCollide(std::function<void()> on_collide) {
		this->on_collide = on_collide;
	}
};


