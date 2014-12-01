function testConstruction()
	io.write("\tConstruction:\t\t")
	
	local time1 = sfml.Time()
	local time2 = sfml.Time()
	
	if time1:asSeconds() ~= time2:asSeconds() then return false end
	if time1:asMilliseconds() ~= time2:asMilliseconds() then return false end
	if time1:asMicroseconds() ~= time2:asMicroseconds() then return false end
	
	time1 = sfml.seconds(10)
	time2 = sfml.milliseconds(10000)

	if time1:asSeconds() ~= time2:asSeconds() then return false end
	if time1:asMilliseconds() ~= time2:asMilliseconds() then return false end
	if time1:asMicroseconds() ~= time2:asMicroseconds() then return false end
	
	return true
end

function testEquality()
	io.write("\tEquality:\t\t")
	return sfml.seconds(1) == sfml.seconds(1)
end

function testLessThan()
	io.write("\tLessThan:\t\t")
	return (sfml.seconds(0.9) < sfml.seconds(1))
end

function testLessThanEquality()
	io.write("\tLessThanEquality:\t")
	return (sfml.seconds(1) <= sfml.seconds(1))
end

function testAdd()
	io.write("\tAdd:\t\t\t")
	return (sfml.microseconds(1) + sfml.microseconds(1) == sfml.microseconds(2))
end

function testSubtract()
	io.write("\tSubtract:\t\t")
	return (sfml.microseconds(1) - sfml.microseconds(1) == sfml.microseconds(0))
end

local testTime = {}

function testTime.performTests()
	print("[TEST]\tTime\t\t\t....")
	print(testConstruction())
	print(testEquality())
	print(testLessThan())
	print(testLessThanEquality())
	print(testAdd())
	print(testSubtract())
end

return testTime
