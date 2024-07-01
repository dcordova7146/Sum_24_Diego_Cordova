#include "pch.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "DinoApp.h"
#include"DinoWindow.h"
#include"Image.h"
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
			-0.5f, -0.5f, 0.0f, 0.0f, //bottom-left
			-0.5f, 0.5f, 0.0f, 1.0f, //upper-left
			0.5f, 0.5f, 1.0f, 1.0f, //upper-right
			0.5f, -0.5f, 1.0f, 0.0f //bottom-right
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

		const char* vertexShaderSource = R"(
			#version 330 core
			layout (location = 0) in vec2 aPos;
			layout (location = 1) in vec2 aTexCoord;

			out vec2 TexCoord;

			void main()
			{
				gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
				TexCoord = aTexCoord;
			}
		)";

		const char* fragmentShaderSource = R"(
			#version 330 core
			out vec4 FragColor;

			in vec2 TexCoord;
			uniform sampler2D image;

			void main()
			{
				FragColor = texture(image, TexCoord);
			}
		)";
		
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		//check for shader compile errors
		int successs;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successs);
		if (!successs)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			DINO_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		//check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successs);
		if (!successs)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			DINO_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}
		//link shaders
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		//check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successs);
		if (!successs)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			DINO_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


		Dino::Image pic{ "..Table/Assets/Images/untitled.png" };

		while (true) {
			OnUpdate();

			glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO); // seeing as we only have a single VAO there no need to bind
			pic.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			DinoWindow::GetWindow()->SwapBuffers();
			DinoWindow::GetWindow()->PollEvents();
		}
	}
}