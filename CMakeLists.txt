# CMakeList.txt: QT_CMake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。

cmake_minimum_required (VERSION 3.20.1)

project (QT_CMake  CXX)

# 添加c++ 17标准支持
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置为Release
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(osg_dir "C:/OSGeo4W")
# 查找Qt5
set(CMAKE_PREFIX_PATH "${osg_dir}/apps/Qt5")
find_package(Qt5 COMPONENTS Widgets Core Gui Xml REQUIRED)
# 设置QGIS包含目录
set(QGIS_INCLUDE_DIRS "${osg_dir}/apps/qgis-ltr/include")
include_directories(${QGIS_INCLUDE_DIRS})
# 设置QGIS库目录
set(GQIS_LIB_DIR "${osg_dir}/apps/qgis-ltr/lib")
link_directories(${GQIS_LIB_DIR})

#set(ENV{GDAL_DATA} "C:/OSGeo4W/share/gdal")
#set(ENV{PROJ_LIB} "C:/OSGeo4W/share/proj")


# 设置ui文件编译生成ui.h
# qt5_wrap_ui(UI_HEADERS widget.ui)
# configure_file(${UI_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR} COPYONLY)


# 编译源文件
file(GLOB header "./*.h")
file(GLOB src "./*.cpp")

set(SOURCES ${header} ${src})
# message(STATUS " 查看路径: ${SOURCES}")

add_executable(${PROJECT_NAME}
    # WIN32 # 设置WIN32，可以去掉控制台
    ${SOURCES}
)

# 设置要链接的库文件的名称
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Xml)

set(GQIS_LIB "${GQIS_LIB_DIR}/qgis_core.lib" "${GQIS_LIB_DIR}/qgis_gui.lib")
target_link_libraries(${PROJECT_NAME} ${GQIS_LIB})


# 拷贝QT_DLL到执行项目目录下
#[[file(GLOB_RECURSE QT_DLLS "C:/OSGeo4W/apps/Qt5/bin/*.dll")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_DLLS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)]]

# 拷贝OSG_DLL到执行项目目录下
file(GLOB_RECURSE OSG_DLLS "${osg_dir}/bin/*.dll")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${OSG_DLLS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# 拷贝GQIS_DLL到执行项目目录下
file(GLOB_RECURSE QGIS_DLLS "${osg_dir}/apps/qgis-ltr/bin/*.dll")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QGIS_DLLS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)

#[[ 拷贝GQIS_plugins_DLL到执行项目目录下
file(GLOB_RECURSE QGIS_plugins_DLLS "${osg_dir}/apps/qgis-ltr/plugins/*.dll")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QGIS_plugins_DLLS} $<TARGET_FILE_DIR:${PROJECT_NAME}>)]]

