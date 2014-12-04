function testConstruction()
	io.write("\tConstruction:\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	
	if vm1.width ~= 1280 or vm1.height ~= 720 or vm1.bpp ~= 32 then return false end
	
	return true
end

function testByVal()
	io.write("\tBy Val:\t\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	local vm2 = vm1:getCopy()
	
	vm1.width = 0
	
	if vm1.width == vm2.width then return false end
	
	return true
end

function testByRef()
	io.write("\tBy Ref:\t\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	local vm2 = vm1
	
	vm1.width = 0
	
	if vm1.width ~= vm2.width then return false end
	
	return true
end

function testWidth()
	io.write("\tWidth:\t\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	
	vm1.width = 0
	
	if vm1.width ~= 0 then return false end
	
	return true
end

function testHeight()
	io.write("\tHeight:\t\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	
	vm1.height = 0
	
	if vm1.height ~= 0 then return false end
	
	return true
end

function testBpp()
	io.write("\tBits Per Pixel:\t\t")
	
	local vm1 = sfml.VideoMode(1280, 720, 32)
	
	vm1.bpp = 0
	
	if vm1.bpp ~= 0 then return false end
	
	return true
end

local videoMode = {}

function videoMode.performTests()
	print("\n[TEST]\tVideoMode\t\t....")
	print(testConstruction())
	print(testByVal())
	print(testByRef())
	print(testWidth())
	print(testHeight())
	print(testBpp())
end

return videoMode
