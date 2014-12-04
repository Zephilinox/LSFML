function testAll()
	io.write("\tAll:\t\t\t")
	
	local rw1 = sfml.RenderWindow(sfml.VideoMode(1280, 720, 32), "Hello")
	rw1:clear(sfml.Color(40, 40, 40, 255))
	rw1:display()
	sfml.sleep(sfml.seconds(0.5))
	
	return true
end

local renderWindow = {}

function renderWindow.performTests()
	print("\n[TEST]\tRenderWindow\t\t....")
	print(testAll())
end

return renderWindow
