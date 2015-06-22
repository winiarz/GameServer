cmake_minimum_required (VERSION 2.6)
project( SpaceStrategyServer )

set( CMAKE_CXX_FLAGS "-std=c++11" )

include_directories("${PROJECT_BINARY_DIR}/Messages"
                    "${PROJECT_BINARY_DIR}/Common/Include")

add_executable(Bin/SpaceStrategyServer "Source/main.cpp"
                                       "Common/Source/InitMessageQueue.cpp")

add_executable(Bin/FirstTest "Test/test.cpp"
                             "Common/Source/InitMessageQueue.cpp")

