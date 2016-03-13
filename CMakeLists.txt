cmake_minimum_required(VERSION 3.0)

set(CPM_MODULE_NAME SSVStart)
include(./cmake/modules/CPM-mod.cmake)

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

CPM_ExportAdditionalIncludeDir("./include")
CPM_InitModule(${CPM_MODULE_NAME})
