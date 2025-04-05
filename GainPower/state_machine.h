#pragma once

#include "state_node.h"

#include <unordered_map>
#include <string>

class StateMachine
{
public:
	
	StateMachine() = default;
	~StateMachine() = default;

	void on_update(float delta);

	void set_entry(const std::string& id);
	void switch_to(const std::string& id);
	void registerState(std::string& id,StateNode* state);

private:

	StateNode* currentState = nullptr;

	bool is_init = false;
    
	std::unordered_map<std::string, StateNode*> state_pool;
};

