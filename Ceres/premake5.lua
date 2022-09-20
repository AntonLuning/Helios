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
        "%{includeDirs.GLFW}"
    }

    links {
        "Helios"
    }

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