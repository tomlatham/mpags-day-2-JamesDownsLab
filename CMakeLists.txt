# - Main CMAKE buildscript for mpags-cipher 
# Comments in a CMAKE Script are lines begining with a '#'

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' command and
#   running make as 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set the C++ standard directly
set(CMAKE_CXX_STANDARD 11)

# - Declare the build of mpags-cipher.cpp
add_executable(mpags-cipher 
mpags-cipher.cpp
MPAGS-CIPHER/TransformChar.cpp
MPAGS-CIPHER/processCommandLine.cpp
MPAGS-CIPHER/readInput.cpp
MPAGS-CIPHER/writeOutput.cpp
MPAGS-CIPHER/CaesarCipher.cpp MPAGS-CIPHER/PrintHelp.cpp MPAGS-CIPHER/PrintHelp.hpp)

target_include_directories(mpags-cipher
PRIVATE MPAGS-CIPHER)

# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
	PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
	)
