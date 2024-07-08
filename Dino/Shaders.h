#pragma once

#include"pch.h"
#include"Utils.h"
#include"ShadersImplementation.h"

namespace Dino
{
	class DINO_API Shaders
	{
	public:
		Shaders(const std::string& vertexFile, const std::string& fragmentFile);
		Shaders(std::string&& vertexFile, std::string&& fragmentFile);

		void Bind();

		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void SetUniform2Ints(std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShadersImplementation> mImplementation;
	};
}