/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    Decoder.cc
 * @brief   The methods of the decoder class.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 23, 2009
 *
 * $Id$
 * $URL$
 *
 */

#include "Decoder.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

Decoder::Decoder()
{
}

Decoder::~Decoder()
{
}

void Decoder::SetFile(string filename)
{
	this->filename = filename;
	std::cout << "FN: " << filename << std::endl;
}

list<Packet> Decoder::GetNext(int number)
{
	std::string command_line;

	std::stringstream number_ss;
	number_ss << number;

	command_line  = "dvbsnoop -s ts -ph 0 -if " + filename + " -N " + number_ss.str();

	FILE *pipe = popen((char *)command_line.c_str(), "r");

	char buffer[128];
	char packet_number_str[10];
	char pid_str[10];
	char c;
	int counter = 0;

	list<Packet> packet_list;
	Packet packet;

	if (pipe == NULL)
	{
		printf("ERROR\n");
	}

	while (!feof(pipe))
	{
		c = fgetc(pipe);

		if (c == '\n')
		{
			buffer[counter] = '\0';

			if (strncmp(buffer, "TS-Packet", 9) == 0)
			{
				strncpy((char *)packet_number_str, buffer + 11, 8);
				packet.num = atoi((const char *)packet_number_str);
			}
			else if (strncmp(buffer, "PID", 3) == 0)
			{
				strncpy((char *)pid_str, buffer + 5, 4);
				packet.pid = atoi((const char *)pid_str);

				packet_list.push_back(packet);
			}

			counter = 0;
		}
		else
		{
			buffer[counter++] = c;
		}
	}

	/* Close pipe */
	pclose(pipe);

	return packet_list;
}

void Decoder::GoToPacket(int number)
{

}

int Decoder::GetTotalPacket()
{
	return 0;
}

std::string Decoder::GetPacketDescription(int pid)
{
	switch (pid)
	{
		case 0:
			return "ISO 13818-1 Program Association Table (PAT)";
			break;

		case 1:
			return "ISO 13818-1 Conditional Access Table (CAT)";
			break;

		case 16:
			return "DVB Network Information Table (NIT), Stuffing Table (ST)";
			break;

		case 17:
			return "DVB Service Description Table (SDT), Bouquet Association Table (BAT)";
			break;

		case 18:
			return "DVB Event Information Table (EIT)";
			break;

		case 20:
			return "DVB Time and Date Table (TDT), Time Offset Table (TOT)";
			break;

		case 8191:
			return "Null Packet";
			break;

		default:
			return "Unknow";
			break;
	}
}
