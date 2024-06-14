cmake_minimum_required(VERSION 3.8)
project("MK7-Revolution" LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-L${CTR_ROOT}/lib -L${DEVKITPRO}/portlibs/3ds/lib -L${DEVKITPRO}/libctrpf/lib -T ${PROJECT_SOURCE_DIR}/3gx.ld -Os -Wl,-Map,${PROJECT_NAME}.map,--gc-sections")
set(CMAKE_CXX_STANDARD_LIBRARIES "-lm -lctrpf -lctru")

add_definitions("-D__3DS__ -DNNSDK -DMAGIC_ENUM_RANGE_MIN=0 -DMAGIC_ENUM_RANGE_MAX=255")

file(GLOB_RECURSE CXX_SOURCE 
"${PROJECT_SOURCE_DIR}/src/*.cpp"
"${PROJECT_SOURCE_DIR}/vendor/mk7-memory/vendor/sead/modules/src/math/*.cpp"
"${PROJECT_SOURCE_DIR}/vendor/mk7-memory/vendor/sead/modules/src/random/*.cpp"
)

add_executable(${PROJECT_NAME} ${CXX_SOURCE}) # create .elf file

target_include_directories(${PROJECT_NAME} PUBLIC
"include" 
"${DEVKITPRO}/libctrpf/include"
"${DEVKITPRO}/libctru/include"
"vendor/glaze/include"
"vendor/magic_enum/include"
"vendor/mk7-memory/include"
"vendor/mk7-memory/vendor/nnheaders/include"
"vendor/mk7-memory/vendor/sead/include"
)

dkp_target_generate_symbol_list(${PROJECT_NAME})