/*
 * Rename.cpp
 *
 *  Created on: Nov 16, 2009
 *      Author: pfsmorigo
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <libglademm.h>
#include <gtkmm.h>

class MainWindow: public Gtk::Window
{
public:
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gnome::Glade::Xml>& glade_xml);
	virtual ~MainWindow();

protected:

};

#endif // MAINWINDOW_H
