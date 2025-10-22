
add_library(module_a
     MyLib.cpp
)
target_include_directories(module_a
        PUBLIC
        "${CMAKE_SOURCE_DIR}/src/"
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include/")
#get_target_property(module_a_SOURCE_DIR module_a  SOURCE_DIR)
#message("module_a_SOURCE_DIR:${module_a_SOURCE_DIR}")