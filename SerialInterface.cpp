#include "stdafx.h"
#include "SerialInterface.h"
#include <iostream>

SerialInterface::SerialInterface()
{
	std::vector <serial::PortInfo> devicesFound = serial::list_ports();

	std::vector <serial::PortInfo>::iterator iter = devicesFound.begin();

	while (iter != devicesFound.end())
	{
		serial::PortInfo device = *iter++;
		std::string port = device.port.c_str();

		try {
			mySerial = new serial::Serial(port, 115200, serial::Timeout::simpleTimeout(250));

			if (mySerial->isOpen())
			{
				std::cout << "Connection success: " << port << "\n";
				connect = true;

				break;
			}
		}
		catch (std::exception &e) {

		}
	}
}
SerialInterface::~SerialInterface()
{

}

void SerialInterface::send(std::string msg)
{
	if (connect)
	{
		mySerial->write(msg);
	}
}

void SerialInterface::getButton()
{
	if (connect)
	{
		mySerial->write("B");

		std::string result = mySerial->readline();

		//std::vector<std::string> pos = split(result, ';');

		std::string b1 = result.substr(0, 1);
		std::string b2 = result.substr(2, 1);

		button1 = std::stoi(b1);
		button2 = std::stoi(b2);
		//std::cout << button1 << std::endl;
	}
}

void SerialInterface::getPositions()
{
	if (connect)
	{
		mySerial->write("P");

		std::string result = mySerial->readline();

		if (result.length() > 5) {
			std::string sub1 = result.substr(0, 4);
			pot1 = std::stoi(sub1);

			std::string sub2 = result.substr(5, 9);
			pot2 = std::stoi(sub2);
		}

	}
}

void SerialInterface::close()
{
	mySerial->flush();
	mySerial->close();
}