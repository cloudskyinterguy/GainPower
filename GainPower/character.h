#pragma once

#include "animation.h"
#include "state_machine.h"
#include "Vector2.h"
#include "timer.h"
#include "collision_manager.h"
#include "collision_box.h"

class Character
{
public:
	Character() = default;
	~Character() = default;

	void decreaseHp();

	virtual void on_input(const ExMessage& msg);
	virtual void on_update(float delta);
	virtual void on_render();

	virtual void on_hurt();

	void switchToState(const std::string& stateId);
	void setAnimation(const std::string& animationId);

	Vector2 getLogicPosCenter() {
		return Vector2(position.x ,position.y - login_h/2);
	}

protected:
	struct AnimationGroup
	{
		Animation left;
		Animation Right;
	};

protected:
	float FLOOR_Y = 620;
	float gravity = 9.8;
	float login_h = 0;

	int hp = 100;

	Vector2 position;
	Vector2 velocity;
	Vector2 size;
	
	bool is_facing_left = true;

	StateMachine stateMachine;

	bool gravity_enabled = true;

	bool is_invulnerable = false;
	Timer invulnerable_timer;
	
	bool is_blink_invisible = false;
	Timer blink_timer;

	CollisionBox* hit_box = nullptr;
	CollisionBox* attack_box = nullptr;

	AnimationGroup currentAnimationGroup;

	std::unordered_map<std::string, AnimationGroup> animation_pool;	//¶¯»­³Ø
private:

};
