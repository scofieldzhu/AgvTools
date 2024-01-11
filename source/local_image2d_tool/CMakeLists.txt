set(proj_name "LocalImage2dTool")

project(${proj_name})

set(OpenCV_DIR "${VCPKG_INSTALLED_DIR}/x64-windows/share/opencv4")
find_package(OpenCV REQUIRED)

file(GLOB
	 SOURCE_FILES 
	 "*.cpp"
	 "*.h"
	 "*.hpp"
)
add_library(${proj_name} SHARED ${SOURCE_FILES})

set_target_properties(${proj_name} PROPERTIES SUFFIX ".agvt")

set_target_properties(${proj_name} PROPERTIES
    DEBUG_POSTFIX _d
)

target_compile_definitions(${proj_name} PRIVATE 
	SPDLOG_COMPILED_LIB
	SPDLOG_SHARED_LIB
	SPDLOG_USE_STD_FORMAT
)

if(WIN32)
	target_compile_definitions(${proj_name} PRIVATE LOCAL_IMAGE2D_TOOL_EXPORT)
endif()

target_include_directories(${proj_name} PRIVATE ${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11

set(deplibs_dbg spdlogd ratel.basic_d agile_vision.basic_d agile_vision.core_d agile_vision.stdtool_d)
set(deplibs_opt spdlog ratel.basic_d agile_vision.basic agile_vision.core agile_vision.stdtool)
target_link_libraries(${proj_name} debug ${deplibs_dbg} optimized ${deplibs_opt})
target_link_libraries(${proj_name} ${OpenCV_LIBS})

install(TARGETS ${proj_name} RUNTIME DESTINATION ${CMAKE_INSTALL_BIN})
install(TARGETS ${proj_name} ARCHIVE DESTINATION ${CMAKE_INSTALL_LIB})
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDE}/local_image2d_tool)



