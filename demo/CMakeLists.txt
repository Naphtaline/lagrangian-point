set(SRCROOT ${PROJECT_SOURCE_DIR}/demo)
set(BINROOT ${PROJECT_BINARY_DIR}/demo)

# Define sources and executable
set(EXECUTABLE_NAME "Demo")

#For the shared library:
set(PROJECT_LINK_LIBS libLagrangianPoint.so)
link_directories(${PROJECT_BINARY_DIR})

# all source files
file(GLOB DEMO_SRC
  ${SRCROOT}/*.hpp
  ${SRCROOT}/*.cpp
)

add_executable(${EXECUTABLE_NAME} ${SRC} ${DEMO_SRC})

file(COPY "${SRCROOT}/resources" DESTINATION "${BINROOT}")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
