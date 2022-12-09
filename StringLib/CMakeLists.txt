file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

<<<<<<< HEAD
add_library(StringLib STATIC ${srcs} ${hdrs})
=======
add_library(${stringlib} STATIC ${srcs} ${hdrs})
>>>>>>> be460bed2fc506bc8304f4a2b396f84db34ab6af
