# Add all src files
file(GLOB LIB_SRC_FILES
  "src/*.c"
  "src/*.cpp")

add_library(Dlx STATIC
  ${LIB_SRC_FILES})

target_include_directories(Dlx PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)
