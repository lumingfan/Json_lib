# Set the project name
project (tests)

add_executable(unit01_tests unit01.cpp)
# add_executable(unit02_tests unit02.cpp)

target_link_libraries(unit01_tests
    src::json_lib
    GTest::GTest 
    GTest::Main
)

# target_link_libraries(unit02_tests
#     src::json_lib
#     GTest::GTest 
#     GTest::Main
# )

add_test(unit01 unit01_tests)
# add_test(unit02 unit02_tests)


