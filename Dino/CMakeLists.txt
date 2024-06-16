set(HEADER_FILES
	include/Dino.h
	DinoApp.h
	Utils.h
)
set(SOURCE_FILES 
	DinoApp.cpp
)

add_library(Dino SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(Dino
	PUBLIC
		$<$<CONFIG:Debug>:DINO_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:DINO_DEBUG=1>
	PRIVATE
		DINO_LIB
)

if(MSVC)
	target_compile_definitions(Dino PUBLIC DINO_MSVC)
endif()


target_precompile_headers(Dino PRIVATE pch.h)

