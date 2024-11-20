cmake_minimum_required(VERSION 3.10)

project(Bank-Management-System)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically search for source files inside "src/"
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*/*.cpp" "main/*.cpp")

# Create the project executable file
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the "include" folder to the header files search path
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link nlohmann_json library
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/nlohmann)

# Add Google Test submodule
add_subdirectory(external/googletest)

# Link Google Test to the test suite
enable_testing()
add_executable(test_suite 
	test/account/AddAccountHolderTest.cpp
	test/account/DisplayAccountHolderTest.cpp
	test/account/RemoveAccountHolderTest.cpp
	test/account/SearchAccountHolderTest.cpp
	test/account/UpdateAccountHolderTest.cpp
	tests/branch/AddBranchTest.cpp
	tests/branch/DisplayBranchTest.cpp
	tests/branch/RemoveBranchTest.cpp
	tests/branch/SearchBranchTest.cpp
)
target_link_libraries(test_suite gtest_main)
add_test(NAME AllTests COMMAND test_suite)
