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
	filename = this->filename;

//	string line;
//	ifstream myfile("output1");
//
//	if (myfile.is_open())
//	{
//		while (!myfile.eof())
//		{
//			getline(myfile, line);
//
//			if (line.substr(0, 9) == "TS-Packet")
//			{
//				packetNumber = atoi(line.substr(11, 8).c_str());
//			}
//			else if (line.substr(0, 3) == "PID")
//			{
//				pid = atoi(line.substr(5, line.find_first_of('(')-6).c_str());
//
//				cout << "[" << packetNumber << "][" << pid << "]" << endl;
//			}
//		}
//		myfile.close();
//	}
//	else cout << "Unable to open file";
}

list<int> Decoder::GetNext(int number)
{
	FILE *pipe = popen("dvbsnoop -s ts -tssubdecode -n 10 -if channel9hdtv_ac3.ts", "r");

	char buffer[128];
	char packet_number_str[10];
	char pid_str[10];
	char c;
	int counter = 0;

	list<int> pid_list;

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
				packet_number = atoi((const char *)packet_number_str);
			}
			else if (strncmp(buffer, "PID", 3) == 0)
			{
				strncpy((char *)pid_str, buffer + 5, 4);
				pid = atoi((const char *)pid_str);

				pid_list.push_back(pid);
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

	return pid_list;
}

void Decoder::GoToPacket(int number)
{

}

int Decoder::GetTotalPacket()
{
	return 0;
}

