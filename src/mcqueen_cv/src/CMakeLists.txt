add_library(mcqueen-cv
	SHARED
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
