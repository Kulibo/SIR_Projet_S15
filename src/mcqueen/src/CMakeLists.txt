add_library(mcqueen
	SHARED)

install(TARGETS mcqueen
	DESTINATION lib)

file(
	GLOB
	headers
	*.hpp
)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME})
