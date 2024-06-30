#include"pch.h"

#include"WindowGLFW.h"
#include"Utils.h"
namespace Dino
{
	void WindowGLFW::CreateWindow(int width, int height, const std::string& windowName)
	{
	// glfw window creation copied from learn triangle cpp from learn open gl
	// --------------------
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			DINO_ERROR("Window failed to create!!!!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);
	}

	void WindowGLFW::CreateWindow(int width, int height, std::string&& windowName)
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			DINO_ERROR("Window failed to create!!!!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);
	}

	int WindowGLFW::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}

	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwTerminate();
	}
}