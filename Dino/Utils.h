#pragma once

#define DINO_GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}

#ifdef DINO_MSVC
	#ifdef DINO_LIB
		#define DINO_API __declspec(dllexport)
	#else
		#define DINO_API __declspec(dllimport)
	#endif
#else 
	#define DINO_API
#endif

#ifdef DINO_DEBUG==2
	#define DINO_LOG(x) std::cout<<x<<std::endl;
	#define DINO_ERROR(x) std::cout<<x<<std::endl;
#elif defined DINO_DEBUG==1
	#define DINO_LOG(x) 
	#define DINO_ERROR(x) std::cout<<x<<std::endl;
#else
	#define DINO_LOG(x)
	#define DINO_ERROR(x)
#endif