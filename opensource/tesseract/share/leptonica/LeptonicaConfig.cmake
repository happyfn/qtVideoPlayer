get_filename_component(VCPKG_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)
# ===================================================================================
#  The Leptonica CMake configuration file
#
#             ** File generated automatically, do not modify **
#
#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    find_package(Leptonica REQUIRED)
#    include_directories(${Leptonica_INCLUDE_DIRS})
#    target_link_libraries(MY_TARGET_NAME ${Leptonica_LIBRARIES})
#
#    This file will define the following variables:
#      - Leptonica_LIBRARIES             : The list of all imported targets for OpenCV modules.
#      - Leptonica_INCLUDE_DIRS          : The Leptonica include directories.
#      - Leptonica_VERSION               : The version of this Leptonica build: "1.84.1"
#      - Leptonica_VERSION_MAJOR         : Major version part of Leptonica_VERSION: "1"
#      - Leptonica_VERSION_MINOR         : Minor version part of Leptonica_VERSION: "84"
#      - Leptonica_VERSION_PATCH         : Patch version part of Leptonica_VERSION: "1"
#
# ===================================================================================

include(CMakeFindDependencyMacro)
if (ON)
    find_dependency(OpenJPEG CONFIG)
endif()
if (ON)
    find_dependency(WebP 0.5.0 CONFIG)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/LeptonicaTargets.cmake)

# ======================================================
#  Version variables:
# ======================================================

SET(Leptonica_VERSION           1.84.1)
SET(Leptonica_VERSION_MAJOR     1)
SET(Leptonica_VERSION_MINOR     84)
SET(Leptonica_VERSION_PATCH     1)

# ======================================================
# Include directories to add to the user project:
# ======================================================

# Provide the include directories to the caller
set(Leptonica_INCLUDE_DIRS      "${VCPKG_IMPORT_PREFIX}/include;${VCPKG_IMPORT_PREFIX}/include/leptonica")

# ====================================================================
# Link libraries:
# ====================================================================

set(Leptonica_LIBRARIES         leptonica)
