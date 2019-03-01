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
			mySerial = new serial::Serial(port, 9600, serial::Timeout::simpleTimeout(15));

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

void SerialInterface::getPositions()
{
	if (connect)
	{
		mySerial->write("P");

		std::string result = mySerial->readline();

		if (result.length() > 5) 
		{
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