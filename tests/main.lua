package.loadlib("../LSFML.dll", "system")()

local testTime = require("System/testTime")
testTime.performTests()

local testClock = require("System/testClock")
testClock.performTests()

local testVector2 = require("System/testVector2")
testVector2.performTests()
