PROJECT(mishen_eclips)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ENABLE_LANGUAGE(ASM)

SET(TOOLCHAIN_DIR /usr/local)

SET(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin)
SET(TOOLCHAIN_LIBC_DIR ${TOOLCHAIN_DIR}/arm-none-eabi/libc)
SET(TOOLCHAIN_INC_DIR ${TOOLCHAIN_LIBC_DIR}/include)
SET(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_LIBC_DIR}/usr/lib)

SET(CMAKE_SYSTEM_NAME Linux CACHE INTERNAL "system name")
SET(CMAKE_SYSTEM_PROCESSOR arm CACHE INTERNAL "processor")

# Компиляторы
SET(CMAKE_C_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc CACHE INTERNAL "")
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-g++ CACHE INTERNAL "")
SET(CMAKE_ASM_COMPILER ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-as CACHE INTERNAL "")

# objcopy и objdump для создания хексов и бинариков
SET(CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objcopy CACHE INTERNAL "")
SET(CMAKE_OBJDUMP ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objdump CACHE INTERNAL "")


# Исходники проекты (наши исходники)
SET(PROJECT_SOURCES
  apt/main.c
)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}/.
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES}) 
