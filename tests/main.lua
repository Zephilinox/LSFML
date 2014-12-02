package.loadlib("../LSFML.dll", "system")()
package.loadlib("../LSFML.dll", "graphics")()

for k, v in pairs(sfml) do
	if string.sub(k, 0, 2) ~= "__" then
		print(k .. "\t\t" .. tostring(v))
	end
end

local testTime = require("System/testTime")
testTime.performTests()

local testClock = require("System/testClock")
testClock.performTests()

local testVector2 = require("System/testVector2")
testVector2.performTests()

local window = sfml.RenderWindow(1280, 720, 32, "hi")

sfml.sleep(sfml.seconds(1))