
#pragma once

#include "../lib/lua/include/lua.hpp"

#include "entity_manager.h"

// will fix later to bind to class methods

// Logging
void BindLoggingMethods(lua_State* lua);

// Game
void BindGameMethods(lua_State* lua);

// Entities
void BindEntityMethods(lua_State* lua, const EntityManager& mgr);



