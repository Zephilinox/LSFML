require "os_copydir" --usermade function to copy a directory

local system = os.get()
local build_tool = ""

--determine what is being used to compile and if that is supported
--environment is used to determine which subfolder of extlibs to use when looking for libraries
if system == "windows" then
    if _ACTION == "codeblocks" or _ACTION == "codelite" or _ACTION == "gmake" then
        environment = "mingw"
    elseif _ACTION == "vs2010" or _ACTION == "vs2008" or _ACTION == "vs2005" or _ACTION == "vs2003" or _ACTION == "vs20002" then
        environment = "msvc"
    else
        print("Using '".._ACTION.."' on '"..system.."' is not supported")
        os.exit();
    end    
elseif system == "macosx" then
    if _ACTION == "xcode3" then
        environment = "mac"
    else
        print("Using '".._ACTION.."' on '"..system.."' is not supported")
        os.exit();
    end
elseif system == "linux" or system == "bsd" or system == "solaris" then
    if _ACTION == "codeblocks" or _ACTION == "codelite" or _ACTION == "gmake" then
        environment = "linux"
    else
        print("Using '".._ACTION.."' on '"..system.."' is not supported")
        os.exit();
    end
else
    print("Unknown system '"..system.."'")
    os.exit();
end

print("system = "..system)
print("environment = "..environment)

local include_dirs_libs = {
"extlibs/headers/SFML/include",
"extlibs/headers/Lua/include",
}

local include_dirs_header_only = {
"include",
"extlibs/headers/LuaBridge/include",
}

local libs = {
"extlibs/"..environment.."/SFML/lib",
"extlibs/"..environment.."/Lua/lib",
}

print("copying test files")
os.copydir("tests", "builds/".._ACTION.."/test")
os.copydir("tests", "builds/".._ACTION.."/bin/Debug/test")
os.copydir("tests", "builds/".._ACTION.."/bin/Release/test") 

--For windows we will want to copy over the .dll's of libraries to the dll folder, e.g. builds/codeblocks/dll
if system == "windows" then
    print("copying DLL files")
    os.mkdir("builds/".._ACTION.."/dll/")
    
    os.copyfile("extlibs/"..environment.."/SFML/bin/openal32.dll", "builds/".._ACTION.."/dll/openal32.dll")
    os.copyfile("extlibs/"..environment.."/SFML/bin/libsndfile-1.dll", "builds/".._ACTION.."/dll/libsndfile-1.dll")
	
    os.copydir("builds/".._ACTION.."/dll", "builds/".._ACTION.."/bin/Debug/") --place alongside executable
    os.copydir("builds/".._ACTION.."/dll", "builds/".._ACTION.."/bin/Release/")
end

solution("LSFML")
    configurations  {"Debug", "Release"}
    location        ("builds/".._ACTION)
    
    project "LSFML"
        language        ("C++")
        location        ("builds/".._ACTION)
        objdir          ("builds/".._ACTION.."/obj")
        
        files           {"libLSFML.cpp", "include/**.hpp", "src/**.cpp"}
		
		if environment == "mingw" or environment == "linux" then
			buildoptions    ("-std=c++11 -Wall -Wextra -Wno-format -Wno-format-extra-args")
		end
        
        includedirs     {include_dirs_header_only}
        libdirs         (libs)
        
        if system == "windows" then
			if environment == "mingw" then
				linkoptions {"-static-libstdc++"}
			end
			
            includedirs (include_dirs_libs)
            libdirs     ("builds/".._ACTION.."/dll")
            defines     {"SFML_STATIC"}
        end
        
        configuration("Debug")
            kind            ("SharedLib")
            defines         {"DEBUG"}
            flags           {"Symbols", "ExtraWarnings"}
            targetdir       ("builds/".._ACTION.."/bin/Debug/")
            
            if system == "windows" then
                links       {"lua52", "sfml-graphics-s-d", "sfml-window-s-d", "sfml-system-s-d"}
            else 
                links       {"lua5.2", "sfml-graphics", "sfml-window", "sfml-system"}
            end

        configuration("Release")
            kind            ("SharedLib")
            defines         {"NDEBUG"}
            flags           {"Optimize"}
            targetdir       ("builds/".._ACTION.."/bin/Release/")
            
            if system == "windows" then
                links       {"lua52", "sfml-graphics-s", "sfml-window-s", "sfml-system-s"}
            else 
                links       {"lua5.2", "sfml-graphics", "sfml-window", "sfml-system"}
            end