workspace "Genesis"
	architecture "x64"

		configurations
		{
				"Debug",
				"Release",
				"Dist"
		}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Genesis"
		location "Genesis"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "hzpch.h"
		pchsource "Genesis/src/hzpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"GN_PLATFORM_WINDOWS",
				"GN_BUILD_DLL"
			}

			postbuildcommands
			{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "GN_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "GN_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "GN_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleAPP"
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
		"Genesis/vendor/spdlog/include",
		"Genesis/src"
	}

	links
	{
		"Genesis"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GN_DIST"
		optimize "On"
