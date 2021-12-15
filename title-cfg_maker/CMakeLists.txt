cmake_minimum_required(VERSION 3.10)

# set the project name
project(title_cfg_maker)

# add the executable
add_executable(title_cfg_maker main.cpp
                               Package1.rc
                               )
