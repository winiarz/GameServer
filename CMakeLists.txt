cmake_minimum_required (VERSION 2.6)
project( SpaceStrategyServer )

set( CMAKE_CXX_FLAGS "-std=c++11" )

include_directories("${PROJECT_BINARY_DIR}/Messages/Include"
                    "${PROJECT_BINARY_DIR}/Common/Include"
                    "${PROJECT_BINARY_DIR}/Test/Include"
                    "${PROJECT_BINARY_DIR}/Include")

add_executable(Bin/SpaceStrategyServer "Source/main.cpp"
                                       "Common/Source/InitMessageQueue.cpp"
                                       "Common/Source/Debug.cpp"
                                       "Source/UserContainer.cpp"
				       "Source/SendingFunctions.cpp")


add_executable(Bin/Test/ServerStartAndPauze "Test/Source/ServerStartAndPauze.cpp"
                                            "Test/Source/getServerStatus.cpp"
                                            "Common/Source/InitMessageQueue.cpp"
                                            "Test/Source/sendMessage.cpp"
                                            )

add_executable(Bin/Test/TimeElapsed "Test/Source/TimeElapsed.cpp"
                                    "Test/Source/getServerStatus.cpp"
                                    "Common/Source/InitMessageQueue.cpp"
                                    "Test/Source/sendMessage.cpp")


add_executable(Bin/Test/RegisterUser "Test/Source/userRegister.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Test/Source/sendMessage.cpp")