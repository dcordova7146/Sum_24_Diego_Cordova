set(HEADER_FILES
	include/Dino.h
	DinoApp.h
	Utils.h
	DinoWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
)
set(SOURCE_FILES 
	DinoApp.cpp
	DinoWindow.cpp
	ThirdParty/codeGLFW/WindowGLFW.cpp
)

add_library(Dino SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(Dino
	PUBLIC
		$<$<CONFIG:Debug>:DINO_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:DINO_DEBUG=1>
	PRIVATE
		DINO_LIB
		DINO_GLFW
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

