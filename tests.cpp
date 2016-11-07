// tests.cpp
// Testing for the KarpMidi library.

#include "KarpMidi.h"

void Test_RtMidi();

void PrintReceivedMessage(double deltaTime, std::vector<unsigned char> *message, void *);

void PrintReceivedMessage(double deltaTime, std::vector<unsigned char> *message, void *) {
  int numBytes = message->size();
  for (unsigned int i = 0; i < numBytes; i++) {
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  }
  std::cout << "deltaTime: " << deltaTime << std::endl;
}

int main() {

  Test_RtMidi();

  return 0;
}

void Test_RtMidi() {

  RtMidiIn *rtmidi = 0;

  std::cout << "Project Magikarp\n";
  std::cout << "Magikarp MIDI finds... ";

  try {
    rtmidi = new RtMidiIn();
    
    std::string portName;
    int numPorts = rtmidi->getPortCount();
    if (numPorts == 0) {
      std::cout << "No ports are open.";
      delete rtmidi;
      return;
    }

    std::cout << numPorts << " ports are open.\n";
    std::cout << "Choosing the first port.\n";

    rtmidi->openPort(0);
    rtmidi->setCallback(&PrintReceivedMessage);
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

  delete rtmidi;
}

