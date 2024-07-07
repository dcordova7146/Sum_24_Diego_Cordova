#pragma once

#include"../../RendererImplementation.h"

namespace Dino
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) override;
		virtual void Draw(Image& pic, int xCoord, int yCoord) override;


	private:

		Shaders mDefaultShaders{
			"../Dino/Assets/Shaders/defaultVertex.glsl",
			"../Dino/Assets/Shaders/defaultFragment.glsl" };
	};
}