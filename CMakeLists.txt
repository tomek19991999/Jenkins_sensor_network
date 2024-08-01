cmake_minimum_required(VERSION 3.10)

project(SensorNetwork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add nlohmann_json library
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.2
)
FetchContent_MakeAvailable(json)

# Add Google Test library
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)
FetchContent_MakeAvailable(googletest)

# Modify Google Test compilation flags to remove -Werror
set_target_properties(gtest PROPERTIES COMPILE_FLAGS "-Wno-error")
set_target_properties(gtest_main PROPERTIES COMPILE_FLAGS "-Wno-error")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define the executable
add_executable(SensorNetwork ${SOURCES})
target_link_libraries(SensorNetwork PRIVATE nlohmann_json::nlohmann_json)

# Define the location of the configuration file
set(CONFIG_FILE ${CMAKE_SOURCE_DIR}/config.json)
# Add a post-build command to copy the configuration file to the build directory
add_custom_command(
    TARGET SensorNetwork POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CONFIG_FILE} $<TARGET_FILE_DIR:SensorNetwork>
)

# Enable testing
enable_testing()

# Add test files
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/test/*.cpp")

# Add source files for testing (excluding main.cpp)
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Define the test executable and include source files for linking
add_executable(runUnitTests ${TEST_SOURCES} ${SOURCES})

# Link Google Test with the test executable
target_link_libraries(runUnitTests gtest gtest_main pthread nlohmann_json::nlohmann_json)

# Register tests
add_test(NAME MyUnitTests COMMAND runUnitTests)
