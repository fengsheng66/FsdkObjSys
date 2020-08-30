#编译plugins_scene
OPTION(BUILD_normal_scene "Buile the normal_scene of cmake of fsdk" OFF)
IF(BUILD_normal_scene)
	ADD_SUBDIRECTORY(normal_scene)
ENDIF()