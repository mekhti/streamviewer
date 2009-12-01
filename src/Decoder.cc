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

using namespace std;

Decoder::Decoder()
{
	string line;
	ifstream myfile("output1");

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);

			if (line.substr(0, 9) == "TS-Packet")
			{
				packetNumber = atoi(line.substr(11, 8).c_str());
			}
			else if (line.substr(0, 3) == "PID")
			{
				pid = atoi(line.substr(5, line.find_first_of('(')-6).c_str());

				cout << "[" << packetNumber << "][" << pid << "]" << endl;
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

Decoder::~Decoder()
{
}
