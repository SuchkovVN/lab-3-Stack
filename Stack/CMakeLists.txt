file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${stack} ${srcs} ${hdrs})

target_link_libraries(${stack} ${stacklib})