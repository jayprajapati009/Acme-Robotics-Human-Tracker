set(GTEST_SHUFFLE 1)

add_executable(
    human-tracker-test
    main.cpp
    test.cpp
)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

target_include_directories(human-tracker-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${OpenCV_LIBS})
target_link_libraries(human-tracker-test PUBLIC gtest ${OpenCV_LIBS})
