workspace "Helios"
    architecture "x86_64"
    startproject "Ceres"
    configurations { "Debug", "Release", "Distribution" }

outputDir = "%{cfg.buildcfg}-%{cfg.architecture}"
buildDir = "%{wks.location}/bin/" .. outputDir .. "/%{prj.name}"
buildObjDir = "%{wks.location}/bin-obj/" .. outputDir .. "/%{prj.name}"

includeDirs = {}
includeDirs["Helios"] = "Helios/Source"
includeDirs["spdlog"] = "Helios/vendor/spdlog/include"
includeDirs["GLFW"] = "Helios/vendor/glfw/include"

include "Helios/Vendor/glfw"

include "Helios"
include "Ceres"