workspace "Niuniu"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Niuniu"
	location "Niuniu"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NN_PLATFORM_WINDOWS",
			"NN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Niuniu/vendor/spdlog/include",
		"Niuniu/src"
	}

	links
	{
		"Niuniu"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NN_DIST"
		optimize "On"