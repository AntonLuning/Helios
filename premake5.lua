workspace "Helios"
    architecture "x86_64"
    startproject "Ceres"
    configurations { "Debug", "Release", "Distribution" }

outputDir = "%{cfg.buildcfg}-%{cfg.architecture}"
buildDir = "%{wks.location}/bin/" .. outputDir .. "/%{prj.name}"
buildObjDir = "%{wks.location}/bin/obj/" .. outputDir .. "/%{prj.name}"

includeDirs = {}
includeDirs["Helios"] = "%{wks.location}/Helios/Source"
includeDirs["spdlog"] = "%{wks.location}/Vendor/spdlog/include"
includeDirs["GLFW"] = "%{wks.location}/Vendor/glfw/include"
includeDirs["glad"] = "%{wks.location}/Vendor/glad/include"

group "Dependencies"
    include "Vendor/glfw"
    include "Vendor/glad"
group ""

include "Helios"
include "Ceres"