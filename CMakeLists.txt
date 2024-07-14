cmake_minimum_required(VERSION 3.25)
project(CP_Training)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/Templates)

add_executable(CP_Training CP_Problem_Solutions/main.cpp CP_Problem_Solutions/FirstQuestion.cpp Templates/Number_Theory.h)


#add_executable(CP_Problem_Solutions CP_Problem_Solutions/FirstQuestion.cpp Templates/Number_Theory.h)