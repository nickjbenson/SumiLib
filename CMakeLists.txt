# CMakeLists.txt

cmake_minimum_required (VERSION 2.8.4)
project (MagikarpMIDI)

# -------

# RTMidi for MIDI I/O. Uses CoreAudio for OS X.
add_definitions(-D__MACOSX_CORE__)

FIND_LIBRARY(COREFOUNDATION_LIBRARY CoreFoundation)

include_directories ("${PROJECT_SOURCE_DIR}/rtmidi")
add_subdirectory (rtmidi)
 
# -------

# add the executable
add_executable(MagikarpMIDI main.cpp)
target_link_libraries(MagikarpMIDI rtmidi)
target_link_libraries(MagikarpMIDI "-framework CoreMidi")
target_link_libraries(MagikarpMIDI "-framework CoreAudio")
target_link_libraries(MagikarpMIDI "-framework CoreFoundation")
target_link_libraries(MagikarpMIDI ${COREFOUNDATION_LIBRARY})