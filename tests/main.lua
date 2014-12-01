package.cpath = package.cpath .. ";../?.dll"
local lsfml = require("LSFML")

local testTime = require("System/testTime")
testTime.performTests()

local testClock = require("System/testClock")
testClock.performTests()
