# Define sources and executable
set(EXECUTABLE_NAME "Demo")

#For the shared library:
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BINROOT ${CMAKE_CURRENT_BINARY_DIR})
set(ENGINE_LIB_DIR ${CMAKE_BINARY_DIR})

if(APPLE)
    set(ENGINE_LIB libLagrangianPoint.dylib)
elseif(WIN32)
    set(ENGINE_LIB libLagrangianPoint.dll)
else()
    set(ENGINE_LIB libLagrangianPoint.so)
endif()

if(MSVC OR CMAKE_GENERATOR STREQUAL Xcode)
    set(ENGINE_LIB_DIR ${ENGINE_LIB_DIR}/Debug)
    set(BINROOT ${BINROOT}/Debug)
endif()

link_directories(${ENGINE_LIB_DIR})

# all source files
file(GLOB DEMO_SRC
  ${SRCROOT}/*.hpp
  ${SRCROOT}/*.cpp
)

add_executable(${EXECUTABLE_NAME} ${DEMO_SRC})
target_link_libraries(${EXECUTABLE_NAME} ${ENGINE_LIB})

file(COPY "${SRCROOT}/resources" DESTINATION "${BINROOT}")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
