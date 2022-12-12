file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${formula} ${srcs} ${hdrs})
target_link_libraries(${formula} ${formulalib})