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

#include <iostream>
#include <gtkmm.h>
#include <libglademm/xml.h>
#include "Decoder.h"
#include "gui/MainWindow.h"
#include "global.h"

using namespace std;

int main (int argc, char *argv[])
{
	Glib::RefPtr<Gnome::Glade::Xml> rptGldWindow;
	Gtk::Main kit(argc, argv);

	// load the interface
	rptGldWindow = Gnome::Glade::Xml::create("../conf/streamviewer.glade");

	// Get the main window
	MainWindow* winMain;
	rptGldWindow->get_widget_derived("winMain", winMain);

	Decoder decoder;

	// start the event loop
	//Gtk::Main::run(*winMain);

	return 0;
}
