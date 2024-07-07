#include "pch.h"
#include "RendererOpenGL.h"
#include "glad/glad.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include"DinoWindow.h"

namespace Dino 
{
	RendererOpenGL::RendererOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			DINO_ERROR("ERROR: Failed to initialize GLAD");
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		mDefaultShaders.LoadSourceCode(
			"../Dino/Assets/Shaders/defaultVertex.glsl",
			"../Dino/Assets/Shaders/defaultFragment.glsl");
	}

	RendererOpenGL::~RendererOpenGL()
	{

	}

	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		float vertices[] = {
			xCoord,					 yCoord,				   0.0f, 0.0f, //bottom-left
			xCoord,					 yCoord + pic.GetHeight(), 0.0f, 1.0f, //upper-left
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f, //upper-right
			xCoord + pic.GetWidth(), yCoord,				   1.0f, 0.0f //bottom-right
		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle
			0, 2, 3 // second triangle
		};

		unsigned VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));//possible error cant see all of code
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		shaders.Bind();
		glBindVertexArray(VAO); // seeing as we only have a single VAO there no need to bind
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}

	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord)
	{
		float vertices[] = {
			xCoord,					 yCoord,				   0.0f, 0.0f, //bottom-left
			xCoord,					 yCoord + pic.GetHeight(), 0.0f, 1.0f, //upper-left
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f, //upper-right
			xCoord + pic.GetWidth(), yCoord,				   1.0f, 0.0f //bottom-right
		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle
			0, 2, 3 // second triangle
		};

		unsigned VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));//possible error cant see all of code
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		mDefaultShaders.Bind();
		mDefaultShaders.SetUniform2Ints(
			"ScreenSize",
			DinoWindow::GetWindow()->GetWidth(),
			DinoWindow::GetWindow()->GetHeight());
		glBindVertexArray(VAO); // seeing as we only have a single VAO there no need to bind
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererOpenGL::ClearScreen()
	{
		glClearColor(1, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}


}
