project "Helios"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-obj/" .. outputdir .. "/%{prj.name}")

    pchheader "hlpch.h"
    pchsource "Source/hlpch.cpp"

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source",
        "Vendor/spdlog/include",
        "Vendor/glfw/include"
    }

    defines { "HL_BUILD_DLL" }

    postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Ceres/\"")
    }

    filter "configurations:Debug"
        defines { "HL_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "HL_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "HL_DIST" }
        runtime "Release"
        optimize "On"