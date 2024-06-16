add_executable(BestGame main.cpp)

target_include_directories(BestGame PRIVATE ../Dino/include)

target_link_libraries(BestGame Dino)