add_executable(human-tracker main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(human-tracker PUBLIC ${OpenCV_LIBS})