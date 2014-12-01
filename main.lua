package.cpath = package.cpath .. ";bin/Debug/?.dll"
package.cpath = package.cpath .. ";bin/Release/?.dll"
local lsfml = require("LSFML-d")

local time1 = sfml.seconds(1)
local time2 = sfml.milliseconds(1000)

if time1 == time2 then
	print("Pass")
end

if not (time1 < time2) then
	print("Pass")
end

if time1 <= time2 then
	print("Pass")
end

time1 = time1 + time2

if time1 == sfml.milliseconds(2000) then
	print("Pass")
end
