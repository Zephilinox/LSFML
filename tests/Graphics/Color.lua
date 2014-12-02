local color = {}

function testConstruction()
	io.write("\tConstruction:\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	
	if col1.r ~= 255 or col1.g ~= 255 or col1.b ~= 255 or col1.a ~= 255 then return false end
	
	return true
end

function testByVal()
	io.write("\tBy Val:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	local col2 = col1:getCopy()
	
	col1.r = 0
	
	if col1.r == col2.r then return false end
	
	return true
end

function testByRef()
	io.write("\tBy Ref:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	local col2 = col1
	
	col1.r = 0
	
	if col1.r ~= col1.r then return false end
	
	return true
end

function testRed()
	io.write("\tRed:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	
	col1.r = 0
	
	if col1.r ~= 0 then return false end
	
	return true
end

function testGreen()
	io.write("\tGreen:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	
	col1.g = 0
	
	if col1.g ~= 0 then return false end
	
	return true
end

function testBlue()
	io.write("\tBlue:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	
	col1.b = 0
	
	if col1.b ~= 0 then return false end
	
	return true
end

function testAlpha()
	io.write("\tAlpha:\t\t\t")
	
	local col1 = sfml.Color(255, 255, 255, 255)
	
	col1.a = 0
	
	if col1.a ~= 0 then return false end
	
	return true
end

function color.performTests()
	print("\n[TEST]\tColor\t\t\t....")
	print(testConstruction())
	print(testByVal())
	print(testByRef())
	print(testRed())
	print(testGreen())
	print(testBlue())
	print(testAlpha())
end

return color
