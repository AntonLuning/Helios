workspace "Helios"
    architecture "x86_64"
    startproject "Ceres"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

include "Helios"
include "Ceres"