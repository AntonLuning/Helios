project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "Off"
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

    filter "configurations:Release"
        runtime "Release"

    filter "configurations:Distribution"
        runtime "Release"