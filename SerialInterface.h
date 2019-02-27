#pragma once

#include <serial\serial.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

class SerialInterface
{
public:
	SerialInterface();
	~SerialInterface();

	bool connect = false;

	void send(std::string msg);
	void getPositions();
	void getButton();

	int getPot1() { return pot1; };
	int getPot2() { return pot2; };

	void close();



private:
	serial::Serial* mySerial;


	int pot1 = 0;
	int pot2 = 0;
	int button1;
	int button2;
};