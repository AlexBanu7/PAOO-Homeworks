# CMake version
cmake_minimum_required(VERSION 3.0)

set(myproject "hello")
# Project name
project(${myproject})

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()    

# Define the executable and link it with the "credit_card" library
add_executable(${PROJECT_NAME} 
    main.cpp
    credit_card.cpp
)

# Link the "credit_card" library to the executable
target_link_libraries(${PROJECT_NAME} credit_card)