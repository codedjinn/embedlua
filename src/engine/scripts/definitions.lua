--
-- Methods with no implementations so that it can be picked up by intellisense as the methods
-- are injected by the system
--

--- @param msg string
function LogInfo(msg) end

--- @param msg string
function LogDebug(msg) end

--- @param msg string
function LogError(msg) end

--
-- Two options, we can manipulate and build up metatable and set functions,
-- or have these global functions and wrapped nicely in the 'system.lua' file.
-- This option feels less bug prone.

-- @param name string
-- @returns number
function Engine_Spawn_Entity(name) end
