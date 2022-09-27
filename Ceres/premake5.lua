project "Ceres"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

	targetdir (buildDir)
	objdir (buildObjDir)

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
		"Helios"
	}

	defines { "GLFW_INCLUDE_NONE" }

	filter "configurations:Debug"
		defines { "HELIOS_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "HELIOS_RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution"
		kind "WindowedApp"
		defines { "HELIOS_DISTRIBUTION" }
		runtime "Release"
		optimize "Full"