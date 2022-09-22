project "Ceres"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
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
        "%{includeDirs.GLFW}",
        "%{includeDirs.glad}",
        "%{includeDirs.ImGui}"
    }

    links {
        "Helios"
    }

    defines { 
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        defines { "HELIOS_DEBUG" }
        runtime "Debug"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines { "HELIOS_RELEASE" }
        runtime "Release"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Distribution"
        defines { "HELIOS_DISTRIBUTION" }
        runtime "Release"
        buildoptions "/MD"
        optimize "Full"