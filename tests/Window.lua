local modules = {}

modules["videoMode"] = require("Window/VideoMode")

local window = {}

function window.performTests()
	print("\n[MODULE]\t\t\tWindow")
	for k, v in pairs(modules) do
		v.performTests()
	end
end

return window
