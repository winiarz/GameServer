cmake_minimum_required (VERSION 2.6)
project( SpaceStrategyServer )

set( CMAKE_CXX_FLAGS "-std=c++11" )

include_directories("${PROJECT_BINARY_DIR}/Messages/Include"
                    "${PROJECT_BINARY_DIR}/Common/Include"
                    "${PROJECT_BINARY_DIR}/Test/Include"
                    "${PROJECT_BINARY_DIR}/Include")

add_library(CommonUtils "Common/Source/InitMessageQueue.cpp")

add_library(TestUtils "Test/Source/getServerStatus.cpp"
                      "Test/Source/sendMessage.cpp"
                      "Test/Source/tryToRegisterUser.cpp"
                      "Test/Source/tryToLoginUser.cpp"
                      "Test/Source/tryToGetPlanetList.cpp"
                      "Test/Source/tryToGetPlanetInfo.cpp"
                      "Test/Source/tryToGetPublicPlanetInfo.cpp")

add_library(Messages "Messages/Source/PlanetCoordinates.cpp"
		      "Messages/Source/Resources.cpp"
		      )

set(ServerLibs CommonUtils Messages)

add_executable(Bin/SpaceStrategyServer "Source/main.cpp"
                                       "Common/Source/Debug.cpp"
                                       "Source/UserContainer.cpp"
				       "Source/SendingFunctions.cpp"
				       "Source/SessionIdContainer.cpp"
				       "Source/Planet.cpp"
				       "Source/Universe.cpp"
				       "Source/PrivatePlanetInfo.cpp"
				       )
target_link_libraries(Bin/SpaceStrategyServer ${ServerLibs})


set(TestLibs TestUtils CommonUtils Messages gtest -pthread) 

add_executable(Bin/Test/ServerStartAndPauze "Test/Source/ServerStartAndPauze.cpp")
target_link_libraries(Bin/Test/ServerStartAndPauze ${TestLibs})

add_executable(Bin/Test/TimeElapsed "Test/Source/TimeElapsed.cpp")
target_link_libraries(Bin/Test/TimeElapsed ${TestLibs})

add_executable(Bin/Test/RegisterUser "Test/Source/userRegister.cpp")
target_link_libraries(Bin/Test/RegisterUser ${TestLibs})

add_executable(Bin/Test/LoginUser "Test/Source/logingUser.cpp")
target_link_libraries(Bin/Test/LoginUser ${TestLibs})
				     
add_executable(Bin/Test/LoginUser2 "Test/Source/LogingUser2.cpp")
target_link_libraries(Bin/Test/LoginUser2 ${TestLibs})
				     
add_executable(Bin/Test/LoginUser3 "Test/Source/logingUser3.cpp")
target_link_libraries(Bin/Test/LoginUser3 ${TestLibs})
				     
add_executable(Bin/Test/AssignMotherPlanet "Test/Source/AssignMotherPlanet.cpp"
                                           "Test/Source/GtestMain.cpp")
target_link_libraries(Bin/Test/AssignMotherPlanet ${TestLibs})
				     
add_executable(Bin/Test/planetInfo "Test/Source/planetsInfo.cpp")
target_link_libraries(Bin/Test/planetInfo ${TestLibs})
				     
add_executable(Bin/Test/planetInfo_2 "Test/Source/planetsInfo_2.cpp")
target_link_libraries(Bin/Test/planetInfo_2 ${TestLibs})
				     
add_executable(Bin/Test/planetInfo_3 "Test/Source/planetsInfo_3.cpp")
target_link_libraries(Bin/Test/planetInfo_3 ${TestLibs})
				     	     
add_executable(Bin/Test/publicPlanetInfo "Test/Source/publicPlanetInfo.cpp")
target_link_libraries(Bin/Test/publicPlanetInfo ${TestLibs})
				     			     
add_executable(Bin/Test/planetInfo_4_planetSize "Test/Source/planetsInfo_4planetSize.cpp")
target_link_libraries(Bin/Test/planetInfo_4_planetSize ${TestLibs})
				     
add_executable(Bin/Test/RegisterUser[tooManyUsers] "Test/Source/userRegister2.cpp")
target_link_libraries(Bin/Test/RegisterUser[tooManyUsers] ${TestLibs})

