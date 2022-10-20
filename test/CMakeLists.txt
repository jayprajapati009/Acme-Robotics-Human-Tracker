set(GTEST_SHUFFLE 1)

add_executable(
    human-tracker-test
    main.cpp
    test.cpp
    ../app/cam_bot.cpp
    ../app/track.cpp
    ../app/detect.cpp
    ../app/Utils.cpp
)

target_include_directories(human-tracker-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
					${OpenCV_INCLUDE_DIRS})
target_link_libraries(human-tracker-test PUBLIC gtest ${OpenCV_LIBS})
