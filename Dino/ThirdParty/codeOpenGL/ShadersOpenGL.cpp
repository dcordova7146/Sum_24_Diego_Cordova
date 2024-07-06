#include"pch.h"
#include"ShadersOpenGL.h"
#include"glad/glad.h"
#include"Utils.h"

namespace Dino
{
	ShadersOpenGL::ShadersOpenGL(const std::string& vertexFile, const std::string& fragmentfile)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string readFile{ ReadFile(vertexFile) };
		const char* sourceCode{ readFile.c_str() };

		glShaderSource(vertexShader, 1, &sourceCode, NULL);
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
	}

	std::string ShadersOpenGL::ReadFile(const std::string& fileName)
	{
		std::ifstream input{ fileName };
		std::string result;
		std::string line;

		while (input)
		{
			std::getline(input, line);
			result.append(line);
			result.append("\n");
		}
		input.close();

		return result;
	}

	std::string ShadersOpenGL::ReadFile(std::string&& fileName)
	{
		std::ifstream input{ fileName };
		std::string result;
		std::string line;

		while (input)
		{
			std::getline(input, line);
			result.append(line);
			result.append("\n");
		}
		input.close();

		return result;
	}


}