project "glad"
	kind "StaticLib"
	language "C"
	staticruntime "On"
	systemversion "latest"

	targetdir (buildDir)
	objdir (buildObjDir)

	files {
		"src/glad.c",
		"include/glad/glad.h",
		"include/KHR/khrplatform.h"
	}

	includedirs { "include" }

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"