/**
 * @file zmqconnectMain.cpp
 * @brief ...
 *
 * This file is created at Almende B.V. It is open-source software and part of the Common 
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from 
 * thread pools and TCP/IP components to control architectures and learning algorithms. 
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * Copyright © 2012 Your Name <your@email.address>
 *
 * @author  ...
 * @date    ...
 * @company Almende B.V. (or your university, institute or company)
 * @case    Artificial Intelligence Module
 */
#include <zmqconnectExt.h>

#include <stdlib.h>
#include <iostream>

using namespace rur;
using namespace std;

/**
 * Every module is a separate binary and hence has its own main method. It is recommended
 * to have a version of your code running without any middleware wrappers, so preferably
 * have this file and the zmqconnect header and code in a separate "aim" directory.
 */
int main(int argc, char *argv[])  {
	zmqconnectExt *m = new zmqconnectExt();

	std::string identifier = "connect";

//	bool connect = (identifier.find("connect") != std::string::npos);
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " /port0 /port1" << endl;
		return EXIT_FAILURE;
	}

	m->Init(identifier);

	m->SetConnectSource(std::string(argv[1]));
	m->SetConnectTarget(std::string(argv[2]));

	do {
		m->Tick();
	} while (!m->Stop()); 

	delete m;

	std::cout << "End of " << identifier << endl;

	return EXIT_SUCCESS;
}
