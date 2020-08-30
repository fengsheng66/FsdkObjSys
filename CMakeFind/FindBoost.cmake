# 查找头文件目录
FIND_PATH(BOOST_INCLUDE_DIR
		sqlite3.h
		$ENV{BOOST_HOME}
)

MACRO(FIND_BOOST_LIB LIBNAME LIBFILE)
	FIND_LIBRARY(${LIBNAME}
		NAMES LIBFILE PATHS $ENV{BOOST_HOME}/lib
     )
ENDMACRO(FIND_BOOST_LIB LIBNAME LIBFILE)

# 查找库
FIND_BOOST_LIB(BOOST_ATOMIC_LIBRARY libboost_atomic-vc120-mt-1_61)
FIND_BOOST_LIB(BOOST_ATOMIC_LIBRARY_DEBUG libboost_atomic-vc120-mt-gd-1_61)

FIND_BOOST_LIB(BOOST_SYSTEM_LIBRARY libboost_system-vc120-mt-1_61)
FIND_BOOST_LIB(BOOST_SYSTEM_LIBRARY_DEBUG libboost_system-vc120-mt-gd-1_61)

FIND_BOOST_LIB(BOOST_FILESYSTEM_LIBRARY libboost_filesystem-vc120-mt-1_61)
FIND_BOOST_LIB(BOOST_FILESYSTEM_LIBRARY_DEBUG libboost_filesystem-vc120-mt-gd-1_61)

IF(BOOST_INCLUDE_DIR)
	SET(BOOST_FOUND TRUE)
ENDIF(BOOST_INCLUDE_DIR)