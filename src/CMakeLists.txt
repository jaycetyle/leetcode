find_package(GTest REQUIRED)

# --------------------------------------------------------------------------------
# Source files
# --------------------------------------------------------------------------------
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(include)

file(GLOB_RECURSE SOURCE *.cc)

# --------------------------------------------------------------------------------
# Build
# --------------------------------------------------------------------------------
add_executable(unittests
               test_main.cc
               ${SOURCE})

target_link_libraries(unittests PRIVATE
                      ${GTEST_BOTH_LIBRARIES}
                      pthread)

gtest_discover_tests(unittests)
