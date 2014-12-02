function testConstruction()
	io.write("\tConstruction:\t\t")
	
	local vec1 = sfml.Vector2(0, 0)
	
	if vec1.x ~= 0 or vec1.y ~= 0 then return false end
	
	return true
end

function testAdd()
	io.write("\tAdd:\t\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = sfml.Vector2(5, 5)
	
	local vec1 = vec1 + vec2
	if vec1.x ~= 15 or vec1.y ~= 15 then return false end
	if vec2.x == 15 or vec2.y == 15 then return false end
	
	return true
end

function testSubtract()
	io.write("\tSubtract:\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = sfml.Vector2(5, 5)
	
	local vec1 = vec1 - vec2
	if vec1.x ~= 5 or vec1.y ~= 5 then return false end
	if vec2.x ~= 5 or vec2.y ~= 5 then return false end
	
	return true
end

function testMultiply()
	io.write("\tMultiply:\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
		
	local vec1 = vec1 * 5
	if vec1.x ~= 50 or vec1.y ~= 50 then return false end
	
	return true
end

function testDivide()
	io.write("\tDivide:\t\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
		
	local vec1 = vec1 / 5
	if vec1.x ~= 2 or vec1.y ~= 2 then return false end
	
	return true
end

function testEquality()
	io.write("\tEquality:\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = sfml.Vector2(5, 5)
	
	
	if vec1 == vec2 then return false end
	vec2 = sfml.Vector2(10, 10)
	if vec1 ~= vec2 then return false end
	
	return true
end

function testByVal()
	io.write("\tBy Val:\t\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = vec1:getCopy()
	
	vec1.x = 5
	vec1.y = 5
	
	if vec1.x == vec2.x or vec1.y == vec2.y then return false end
	
	return true
end

function testByRef()
	io.write("\tBy Ref:\t\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = vec1
	
	vec1.x = 5
	vec1.y = 5
	
	if vec1.x ~= vec2.x or vec1.y ~= vec2.y then return false end
	
	return true
end

function testProperties()
	io.write("\tProperties:\t\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = sfml.Vector2(5, 5)
	
	vec2.x = vec2.x + vec1.x
	vec2.y = vec2.y + vec1.y
	
	if vec2.x ~= 15 or vec2.y ~= 15 then return false end
	
	return true
end

local vector2 = {}

function vector2.performTests()
	print("\n[TEST]\tVector2\t\t\t....")
	print(testConstruction())
	print(testAdd())
	print(testSubtract())
	print(testMultiply())
	print(testDivide())
	print(testEquality())
	print(testByVal())
	print(testByRef())
	print(testProperties())
	
end

return vector2
