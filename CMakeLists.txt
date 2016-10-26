# CMakeLists.txt

cmake_minimum_required (VERSION 2.8.4)
project (KarpMidi)
link_directories(${PROJECT_SOURCE_DIR}/bin)

# -------

# RTMidi for MIDI I/O.
#add_library(rtmidi ./rtmidi/RtMidi.cpp)

include_directories ("${PROJECT_SOURCE_DIR}/rtmidi")
set (rtmidiSrc ./rtmidi/RtMidi.cpp)
#ADD_EXECUTABLE(MantaMIDI ${Manta_RtMidi_Srcs})

if (APPLE)
  # OS X via CoreMidi
  add_definitions(-D__MACOSX_CORE__)
  find_library(coreFoundationLibrary CoreFoundation)
endif (APPLE)
if (MINGW)
  # Windows via Multimedia Library
  add_definitions(-D__WINDOWS_MM__)
endif (MINGW)
 
# -------

# add the executable
add_executable(KarpMidi tests.cpp ${rtmidiSrc})
#target_link_libraries(KarpMidi rtmidi)

if (APPLE)
  target_link_libraries(KarpMidi "-framework CoreMidi")
  target_link_libraries(KarpMidi "-framework CoreAudio")
  target_link_libraries(KarpMidi "-framework CoreFoundation")
  target_link_libraries(KarpMidi ${COREFOUNDATION_LIBRARY})
endif (APPLE)
if (MINGW)
  target_link_libraries(KarpMidi "winmm.lib")
endif (MINGW)