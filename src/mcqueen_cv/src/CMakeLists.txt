file(
    GLOB
    sources
    *.cpp
    )

add_library(mcqueen-cv
	SHARED
    ${sources}
	)

target_include_directories(mcqueen-cv PUBLIC "${mcn_path}")
target_link_libraries(mcqueen-cv PUBLIC "${mcn_lib}")

install(TARGETS mcqueen-cv
	DESTINATION lib)

file(
	GLOB
	headers
	*.hpp)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME})
