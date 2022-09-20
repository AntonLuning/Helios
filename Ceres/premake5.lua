project "Ceres"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-obj/" .. outputdir .. "/%{prj.name}")

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "%{wks.location}/Helios/Vendor/spdlog/include",
		"%{wks.location}/Helios/Source"
    }

    defines {
        "HL_PLATFORM_WINDOWS"
    }

    links {
        "Helios"
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