function testConstruction()
	io.write("\tConstruction:\t\t")
	
	local vec1 = sfml.Vector2(0, 0)
	local vec2 = sfml.Vector2(0, 0)
	
	if vec1.x ~= 0 or vec1.y ~= 0 or vec2.x ~= 0 or vec2.y ~= 0 then return false end
	
	return true
end

function testCopyAssignment()
	io.write("\tCopy Assignment:\t")
	
	local vec1 = sfml.Vector2(10, 10)
	local vec2 = vec1
	
	if vec1.x ~= 10 or vec1.y ~= 10 or vec2.x ~= 10 or vec2.y ~= 10 then return false end
	
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

local testVector2 = {}

function testVector2.performTests()
	print("\n[TEST]\tVector2\t\t\t....")
	print(testConstruction())
	print(testCopyAssignment())
	print(testByVal())
	print(testByRef())
	print(testProperties())
	
end

return testVector2
