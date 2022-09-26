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
includeDirs["glm"] = "%{wks.location}/Vendor/glm"
includeDirs["GLFW"] = "%{wks.location}/Vendor/glfw/include"
includeDirs["glad"] = "%{wks.location}/Vendor/glad/include"
includeDirs["ImGui"] = "%{wks.location}/Vendor/imgui"

group "Dependencies"
	include "Vendor/glfw"
	include "Vendor/glad"
	include "Vendor/imgui"
group ""

include "Helios"
include "Ceres"