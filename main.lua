package.cpath = package.cpath .. ";bin/Debug/?.dll"
package.cpath = package.cpath .. ";bin/Release/?.dll"
local lsfml = require("LSFML-d")

whileClock = sfml.Clock()

while true do
	print(tostring(whileClock:restart():asMicroseconds()))
	sfml.sleep(sfml.seconds(0.5))
end
