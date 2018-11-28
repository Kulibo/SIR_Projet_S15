file(
    GLOB
    sources
    *.cpp
    )

add_library(mcqueen-cv
	SHARED
    ${sources}
	)

install(TARGETS mcqueen-cv
	DESTINATION lib)

file(
	GLOB
	headers
	*.hpp)

target_link_libraries(mcqueen-cv mcqueen)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME})
