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
				       "Source/SendingFunctions.cpp"
				       "Source/SessionIdContainer.cpp"
				       "Source/Planet.cpp"
				       "Source/Universe.cpp"
				       "Messages/Source/PlanetCoordinates.cpp"
				       )


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

add_executable(Bin/Test/LoginUser "Test/Source/logingUser.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Test/Source/sendMessage.cpp")
				     
add_executable(Bin/Test/LoginUser2 "Test/Source/LogingUser2.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Test/Source/sendMessage.cpp")	
				     
add_executable(Bin/Test/LoginUser3 "Test/Source/logingUser3.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Test/Source/sendMessage.cpp")	
				     
add_executable(Bin/Test/AssignMotherPlanet "Test/Source/AssignMotherPlanet.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     
add_executable(Bin/Test/planetInfo   "Test/Source/planetsInfo.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Test/Source/tryToGetPlanetInfo.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     
add_executable(Bin/Test/planetInfo_2   "Test/Source/planetsInfo_2.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Test/Source/tryToGetPlanetInfo.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     
add_executable(Bin/Test/planetInfo_3   "Test/Source/planetsInfo_3.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Test/Source/tryToGetPlanetInfo.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     	     
add_executable(Bin/Test/publicPlanetInfo  "Test/Source/publicPlanetInfo.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Test/Source/tryToGetPlanetInfo.cpp"
				     "Test/Source/tryToGetPublicPlanetInfo.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     			     
add_executable(Bin/Test/planetInfo_4_planetSize   "Test/Source/planetsInfo_4planetSize.cpp"
				     "Test/Source/tryToLoginUser.cpp"
				     "Test/Source/tryToRegisterUser.cpp"
				     "Test/Source/tryToGetPlanetList.cpp"
				     "Test/Source/tryToGetPlanetInfo.cpp"
				     "Common/Source/InitMessageQueue.cpp"
				     "Messages/Source/PlanetCoordinates.cpp"
				     "Test/Source/sendMessage.cpp")
				     
add_executable(Bin/Test/RegisterUser[tooManyUsers] "Test/Source/userRegister2.cpp"
						   "Test/Source/tryToRegisterUser.cpp"
				                   "Common/Source/InitMessageQueue.cpp"
						   "Test/Source/sendMessage.cpp")