project "Helios"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	targetdir (buildDir)
	objdir (buildObjDir)

	pchheader "HeliosPCH.h"
	pchsource "Source/HeliosPCH.cpp"

	files {
		"Source/**.h",
		"Source/**.cpp"
	}

	includedirs {
		"%{includeDirs.Helios}",
		"%{includeDirs.spdlog}",
		"%{includeDirs.glm}",
		"%{includeDirs.GLFW}",
		"%{includeDirs.glad}",
		"%{includeDirs.ImGui}"
	}
	
	links {
		"GLFW",
		"glad",
		"ImGui",
		"opengl32.lib"
	}

	defines { "GLFW_INCLUDE_NONE", "_CRT_SECURE_NO_WARNINGS" }

	filter "configurations:Debug"
		defines { "HELIOS_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "HELIOS_RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		defines { "HELIOS_DISTRIBUTION" }
		runtime "Release"
		optimize "Full"