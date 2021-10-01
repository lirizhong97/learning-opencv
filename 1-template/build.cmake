# 查找OpenCV库
find_package(OpenCV REQUIRED)

# 可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 构建OpenCV应用
# APP 业务标识
# TARGET 目标名称
macro(build_opencv_app APP TARGET)

	# 包含依赖头文件
    include_directories(${OpenCV_INCLUDE_DIRS})
	include_directories(${PROJECT_SOURCE_DIR})
	
	# 递归查找所有源文件
	file(GLOB_RECURSE SRC_FILES  "*.cc" "*.cpp" "*.c")

	# 构建可执行文件
	add_executable(${TARGET} ${SRC_FILES})

	# 链接依赖库
	target_link_libraries(${TARGET} ${OpenCV_LIBS})

endmacro()
