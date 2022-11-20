file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${stacklib} STATIC ${srcs} ${hdrs})