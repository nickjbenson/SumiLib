# CMakeLists.txt

cmake_minimum_required (VERSION 2.8.4)
project (KarpMIDI)
link_directories(${PROJECT_SOURCE_DIR}/bin)

# -------

# RTMidi for MIDI I/O. Uses CoreAudio for OS X.
add_definitions(-D__MACOSX_CORE__)

FIND_LIBRARY(COREFOUNDATION_LIBRARY CoreFoundation)

include_directories ("${PROJECT_SOURCE_DIR}/rtmidi")
add_subdirectory (rtmidi)
 
# -------

# add the executable
add_executable(KarpMIDI main.cpp)
target_link_libraries(KarpMIDI rtmidi)
target_link_libraries(KarpMIDI "-framework CoreMidi")
target_link_libraries(KarpMIDI "-framework CoreAudio")
target_link_libraries(KarpMIDI "-framework CoreFoundation")
target_link_libraries(KarpMIDI ${COREFOUNDATION_LIBRARY})