#编译FsdkKernel
OPTION(BUILD_FsdkKernel "Build the FsdkKernel of cmake of fsdk" ON)
IF(BUILD_FsdkKernel)
	ADD_SUBDIRECTORY(FsdkKernel)
ENDIF()

#编译FsdkObj
OPTION(BUILD_FsdkObj "Build the FsdkObj of cmake of fsdk" ON)
IF(BUILD_FsdkObj)
	ADD_SUBDIRECTORY(FsdkObj)
ENDIF()
