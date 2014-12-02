local modules = {}

modules["color"] = require("Graphics/Color")
modules["renderWindow"] = require("Graphics/RenderWindow")

local graphics = {}

function graphics.performTests()
	print("\n[MODULE]\t\t\tGraphics")
	for k, v in pairs(modules) do
		v.performTests()
	end
end

return graphics
