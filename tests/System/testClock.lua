function testElapsedTime()
	io.write("\tElapsedTime:\t\t")
	return (sfml.Clock():getElapsedTime() >= sfml.Time())
end

function testRestart()
	io.write("\tRestart:\t\t")
	return (sfml.Clock():restart() >= sfml.Time())
end

local testClock = {}

function testClock.performTests()
	print("\n[TEST]\tClock\t\t\t....")
	print(testElapsedTime())
	print(testRestart())
end

return testClock
