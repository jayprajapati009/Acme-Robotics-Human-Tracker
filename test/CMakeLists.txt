set(GTEST_SHUFFLE 1)

add_executable(
    human-tracker-test
    main.cpp
    test.cpp
)

target_include_directories(human-tracker-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(human-tracker-test PUBLIC gtest)
