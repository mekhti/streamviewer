/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    main.cc
 * @brief   The main function.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 16, 2009
 *
 * $Id$
 * $URL$
 *
 */

#include "main.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	/* Load the interface. */
	rptGlade = Gnome::Glade::Xml::create("../conf/streamviewer.glade");

	/* Get the main window. */
	rptGlade->get_widget_derived("winMain", winMain);

	Gtk::Main::run(*winMain);

	return 0;
}
