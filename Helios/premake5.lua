project "Helios"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
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

    defines { 
        "HELIOS_BUILD_DLL", 
        "GLFW_INCLUDE_NONE"
    }

    postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/Ceres/\"")
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