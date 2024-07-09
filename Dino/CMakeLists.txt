set(HEADER_FILES
	include/Dino.h
	DinoApp.h
	Utils.h
	DinoWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
	Image.h
	ImageImplementation.h
	ThirdParty/codeOpenGL/ImageOpenGL.h
	Shaders.h
	ShadersImplementation.h
	ThirdParty/codeOpenGL/ShadersOpenGL.h
	Renderer.h
	RendererImplementation.h
	ThirdParty/codeOpenGL/RendererOpenGL.h
	Events.h
	DinoKeys.h

)
set(SOURCE_FILES 
	DinoApp.cpp
	DinoWindow.cpp
	ThirdParty/codeGLFW/WindowGLFW.cpp
	Image.cpp
	ThirdParty/codeOpenGL/ImageOpenGL.cpp
	Shaders.cpp
	ThirdParty/codeOpenGL/ShadersOpenGL.cpp
	Renderer.cpp
	ThirdParty/codeOpenGL/RendererOpenGL.cpp
	Events.cpp
)

add_library(Dino SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(Dino
	PUBLIC
		$<$<CONFIG:Debug>:DINO_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:DINO_DEBUG=1>
		DINO_GLFW
	PRIVATE
		DINO_LIB
		DINO_OPENGL
)

if(MSVC)
	target_compile_definitions(Dino PUBLIC DINO_MSVC)
endif()

target_include_directories(Dino PRIVATE ${CMAKE_SOURCE_DIR}/Dino)
target_include_directories(Dino PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(Dino PRIVATE ${CMAKE_SOURCE_DIR}/glad/include)

target_link_libraries(Dino glfw glad stbi)

target_precompile_headers(Dino PRIVATE pch.h)

