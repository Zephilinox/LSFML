package.loadlib("../LSFML.dll", "system")()
package.loadlib("../LSFML.dll", "window")()
package.loadlib("../LSFML.dll", "graphics")()

for k, v in pairs(sfml) do
	if string.sub(k, 0, 2) ~= "__" then
		print(k .. "\t\t" .. tostring(v))
	end
end

local system = require("System")
system.performTests()

local window = require("Window")
window.performTests()

local graphics = require("Graphics")
graphics.performTests()