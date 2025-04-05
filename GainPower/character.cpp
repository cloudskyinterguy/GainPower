#include "character.h"

Character::Character()
{
	hit_box = CollisionManager::getInstance()->createCollisionBox();
	attack_box = CollisionManager::getInstance()->createCollisionBox();

	invulnerable_timer.set_one_shot(true);
	invulnerable_timer.set_wait_time(1.0f);
	invulnerable_timer.set_callback([this]() {
		is_invulnerable = false;
		});

	blink_timer.set_one_shot(false);
	blink_timer.set_wait_time(0.075f);
	blink_timer.set_callback([this]() {
		is_blink_invisible = false;
		});

}

Character::~Character() {
	CollisionManager::getInstance()->destoryCollisionBox(hit_box);
	CollisionManager::getInstance()->destoryCollisionBox(attack_box);
}

void Character::decreaseHp() {
	if (is_invulnerable) {
		return;
	}
	hp -= 1;
	
	if (hp>0)
	{
		is_invulnerable = true;
	}
	on_hurt();
}

void Character::on_input(const ExMessage& msg) {

}

void Character::on_update(float delta) {
	stateMachine.on_update(delta);

	if (hp <= 0) velocity.x = 0;

	if (gravity_enabled)velocity.y += gravity * delta;

	position += velocity * delta;	//Î»ÒÆÈ·¶¨

	//ÐÞÕýyÖá±ÜÃâÏÂ×¹
	if (position.y > FLOOR_Y) {
		position.y = FLOOR_Y;
		velocity.y = 0;
	}

	//ÐÞÕýxÖá£¬ÒÔ·ÀÖ¹Ô½½ç

	//¹¥»÷Åö×²Ïä¸úËæÍæ¼Ò
	attack_box->setPosition(getLogicPosCenter());

	invulnerable_timer.on_update(delta);

	if(is_blink_invisible)
	blink_timer.on_update(delta);

	Animation& anim = (is_facing_left) ?
		currentAnimationGroup.left :
		currentAnimationGroup.Right;

	anim.on_update(delta);
	anim.setPosition(position);
}

void Character::on_render() {
	Animation& anim = (is_facing_left) ?
		currentAnimationGroup.left :
		currentAnimationGroup.Right;
	anim.on_render();
}

void Character::on_hurt() {

}

void Character::switchToState(const std::string& stateId) {
	stateMachine.switch_to(stateId);
}

void Character::setAnimation(const std::string& animationId) {
	currentAnimationGroup = animation_pool[animationId];

	currentAnimationGroup.left.restart();
	currentAnimationGroup.Right.restart();
}