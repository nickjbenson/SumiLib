#include <iostream>
#include <cstdlib>
#include "RtMidi.h"

void OnReceiveMessage(double deltaTime, std::vector<unsigned char> *message, void *);

int main() {

  RtMidiIn *rtmidi = 0;

  std::cout << "Project Magikarp\n";
  std::cout << "Magikarp MIDI finds... ";

  try {
    rtmidi = new RtMidiIn();
    
    std::string portName;
    int numPorts = rtmidi->getPortCount();
    if (numPorts == 0) {
      std::cout << "No ports are open.";
      goto cleanup;
    }

    std::cout << numPorts << " ports are open.\n";
    std::cout << "Choosing the first port.\n";

    rtmidi->openPort(0);
    rtmidi->setCallback(&OnReceiveMessage);
    rtmidi->ignoreTypes( false, false, false );
    
    std::cout << "Reading MIDI input. Press Enter to quit.\n\n";
    char input;
    std::cin.get(input);
  }
  catch(RtMidiError &error) {
    std::cout << "Oh shit son!\n";
    error.printMessage();
  }
  catch (...) { }

cleanup:
  if (rtmidi != 0) {
    delete rtmidi;
  }

  return 0;
}

void OnReceiveMessage(double deltaTime, std::vector<unsigned char> *message, void *) {
  unsigned int numBytes = message->size();
  for (unsigned int i = 0; i < numBytes; i++) {
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  }
  std::cout << "deltaTime: " << deltaTime << std::endl;
}