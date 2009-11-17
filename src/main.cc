/*
 * main.cpp
 *
 *  Created on: Nov 16, 2009
 *      Author: pfsmorigo
 */

#include <gtkmm.h>
#include <libglademm/xml.h>
#include "gui/MainWindow.h"
#include "global.h"

using namespace std;

int main (int argc, char *argv[])
{
//	applicationPath = Glib::get

	Glib::RefPtr<Gnome::Glade::Xml> rptGldWindow;
	Gtk::Main kit(argc, argv);

	// load the interface
	rptGldWindow = Gnome::Glade::Xml::create("../conf/streamviewer.glade");

	// Get the main window
	MainWindow* winMain;
	rptGldWindow->get_widget_derived("winMain", winMain);

	// start the event loop
	Gtk::Main::run(*winMain);

	return 0;
}

