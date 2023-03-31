include(FetchContent)

FetchContent_Declare(
        doctest
        GIT_REPOSITORY https://gitee.com/acking-you/doctest.git
        GIT_TAG origin/master
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(doctest)
include(${PROJECT_SOURCE_DIR}/cmake/dll_support.cmake)

file(GLOB  TEST_SRC ${PROJECT_SOURCE_DIR}/tests/test_*.cc)

add_executable(${PROJECT_NAME}_test ${TEST_SRC})
target_link_libraries(${PROJECT_NAME}_test PRIVATE doctest_with_main  ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_test PUBLIC ${PROJECT_SOURCE_DIR}/src)


add_executable(${PROJECT_NAME}_main show_window_main.cc)
target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_main PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(main1 main1.cc)
target_link_libraries(main1 PRIVATE ${PROJECT_NAME})
target_include_directories(main1 PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(main2 main2.cc)
target_link_libraries(main2 PRIVATE ${PROJECT_NAME})
target_include_directories(main2 PUBLIC ${PROJECT_SOURCE_DIR}/src)

dll_support(${PROJECT_NAME}_test ${PROJECT_NAME}_main main1 main2)
