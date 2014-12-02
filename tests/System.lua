local modules = {}

modules["time"] = require("System/Time")
modules["clock"] = require("System/Clock")
modules["vector2"] = require("System/Vector2")

local system = {}

function system.performTests()
	print("\n[MODULE]\t\t\tSystem")
	for k, v in pairs(modules) do
		v.performTests()
	end
end

return system
