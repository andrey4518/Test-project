cmake_minimum_required(VERSION 3.13.0)
project(Test-project VERSION 0.1.0)

include(CTest)
enable_testing()

SET (SRCS main.cpp
          AppSettings.cpp
          SignalGenerator.cpp
          SignalFilter.cpp
          KalmanFilter/Kalman.cpp)

add_executable(Test-project ${SRCS})

set (BOOST_ROOT "/usr/lib/x86_64-linux-gnu")

find_package(Boost COMPONENTS system program_options REQUIRED)

if(Boost_FOUND)
  message(STATUS "Boost version: ${Boost_VERSION}")
  target_include_directories(Test-project PUBLIC ${Boost_INCLUDE_DIRS})
  target_link_libraries(Test-project LINK_PUBLIC ${Boost_LIBRARIES})
else()
  message(STATUS "Boost NOT Found !")
endif(Boost_FOUND)

target_include_directories(Test-project PUBLIC "KalmanFilter")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
