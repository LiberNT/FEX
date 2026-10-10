target_sources(CommonWindowsRuntime PRIVATE Alloc.cpp IO.cpp Math.cpp String.cpp Misc.cpp CRT.cpp MuslImports.c)
add_subdirectory(Musl)
