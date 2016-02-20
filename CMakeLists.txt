cmake_minimum_required(VERSION 3.0)

#-----------------------------------------------------------------------
# CPM configuration
#-----------------------------------------------------------------------
set(CPM_MODULE_NAME SSVStart)
set(CPM_LIB_TARGET_NAME ${CPM_MODULE_NAME})

if ((DEFINED CPM_DIR) AND (DEFINED CPM_UNIQUE_ID) AND (DEFINED CPM_TARGET_NAME))
	set(CPM_LIB_TARGET_NAME ${CPM_TARGET_NAME})
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CPM_DIR})
	include(CPM)
else()
	set(CPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpm-packages" CACHE TYPE STRING)
	find_package(Git)
	if(NOT GIT_FOUND)
		message(FATAL_ERROR "CPM requires Git.")
	endif()
	if (NOT EXISTS ${CPM_DIR}/CPM.cmake)
		message(STATUS "Cloning repo (https://github.com/iauns/cpm)")
		execute_process(
			COMMAND "${GIT_EXECUTABLE}" clone https://github.com/iauns/cpm ${CPM_DIR}
			RESULT_VARIABLE error_code
			OUTPUT_QUIET ERROR_QUIET)
		if(error_code)
			message(FATAL_ERROR "CPM failed to get the hash for HEAD")
		endif()
	endif()
	include(${CPM_DIR}/CPM.cmake)
endif()

SET(SSVDepsRoot "https://github.com/lukeadams/")
CPM_AddModule("SSVCMake"
	GIT_REPOSITORY "${SSVDepsRoot}SSVCMake"
	GIT_TAG "cpm")
SET(CMAKE_MODULE_PATH ${CPM_KV_SOURCEDIR_MAP_SSVCMake}/cmake/modules ${CMAKE_MODULE_PATH})
include(SSVCMake)

CPM_AddModule("SSVUtils" #Not workign rn
	GIT_REPOSITORY "${SSVDepsRoot}SSVUtils"
	GIT_TAG "cpm")
CPM_AddModule("vrm_pp"
	GIT_REPOSITORY "${SSVDepsRoot}vrm_pp"
	GIT_TAG "cpm")
## Basic project setup.
#vrm_cmake_init_project(SSVStart)
#vrm_cmake_find_extlib(vrm_pp)
#vrm_cmake_find_extlib(SSVUtils)
#SSVCMake_findSFML()
#
## Alias the include directory.
#set(SSVSTART_INC_DIR "${SSVSTART_SOURCE_DIR}/include/")
#
## Other compiler flags.
#vrm_cmake_add_common_compiler_flags()
#
## Setup user options.
#vrm_cmake_add_option_memcheck()
#vrm_cmake_add_option_no_exceptions()
#vrm_cmake_add_option_werror()
#
## The `check` target runs all tests and examples.
#vrm_check_target()
#
## Add subdirectories.
#add_subdirectory(test)
#
## Create header-only install target (automatically glob)
#vrm_cmake_header_only_install_glob("${SSVSTART_INC_DIR}" "include")
CPM_ExportAdditionalIncludeDir("./include")
CPM_InitModule(${CPM_MODULE_NAME})
