#include "pch.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "DinoApp.h"
#include"DinoWindow.h"
#include"Image.h"
#include"Shaders.h"
#include"stb_image.h"

namespace Dino {
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		DinoWindow::Init();
		DinoWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			DINO_ERROR("ERROR: Failed to initialize GLAD");
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		////VERTEX DATA ////

		float vertices[] = {
			10, 10, 0.0f, 0.0f, //bottom-left
			10, 100, 0.0f, 1.0f, //upper-left
			100, 100, 1.0f, 1.0f, //upper-right
			100, 10, 1.0f, 0.0f //bottom-right
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

		//// SHADERS ////

		
		Dino::Shaders shaders{
			"../Dino/Assets/Shaders/defaultVertex.glsl",
			"../Dino/Assets/Shaders/defaultFragment.glsl" };

		//// TEXTURE //////

		Dino::Image pic{ "../Dino/Assets/Images/temp.png" };

		while (true) {
			OnUpdate();

			glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shaders.Bind();
			shaders.SetUniform2Ints("ScreenSize", 1000, 800);
			glBindVertexArray(VAO); // seeing as we only have a single VAO there no need to bind
			pic.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			DinoWindow::GetWindow()->SwapBuffers();
			DinoWindow::GetWindow()->PollEvents();
		}
	}
}