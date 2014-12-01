package.cpath = package.cpath .. ";bin/Debug/?.dll"
package.cpath = package.cpath .. ";bin/Release/?.dll"
local lsfml = require("LSFML-d")

print("hi1")

sfml.print("hi2\n")
sfml.clockPrint("hi2")
