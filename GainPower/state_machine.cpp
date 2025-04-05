#include "state_machine.h"

void StateMachine::on_update(float delta)
{
	if (currentState == nullptr)
	{
		return;
	}
	if (!is_init)
	{
		currentState->on_enter();
		is_init = true;
	}
	currentState->on_update(delta);
}

void StateMachine::set_entry(const std::string& id)
{
	currentState = state_pool[id];
}

void StateMachine::switch_to(const std::string& id)
{
	if (currentState)
	{
		currentState->on_exit();
	}
	currentState = state_pool[id];
	if (currentState)
	{
		currentState->on_enter();
	}
}

void StateMachine::registerState(std::string& id, StateNode* state)
{
	state_pool[id] = state;
}

