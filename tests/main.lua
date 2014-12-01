package.cpath = package.cpath .. ";../bin/Debug/?.dll"
package.cpath = package.cpath .. ";../bin/Release/?.dll"
local lsfml = require("LSFML-d")

local testTime = require("System/testTime")
testTime.performTests()

local testClock = require("System/testClock")
testClock.performTests()
