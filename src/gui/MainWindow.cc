/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    MainWindow.cc
 * @brief   The methods of the main class of the application.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 16, 2009
 *
 * $Id$
 * $URL$
 *
 */

#include "MainWindow.h"
#include "global.h"
#include <iostream>
#include <gtkmm.h>

using namespace std;

MainWindow::MainWindow(BaseObjectType* base_object, const Glib::RefPtr<Gnome::Glade::Xml>& glade_xml) :	Gtk::Window(base_object)
{
	rptGlade->get_widget("tvwPacketList", tvwPacketList);

	/* Create the Tree model. */
	refLstPacketList = Gtk::ListStore::create(mclPacketList);
	tvwPacketList->set_model(refLstPacketList);

	/* Fill the TreeView's model. */
	Gtk::TreeModel::Row row = *(refLstPacketList->append());
	row[mclPacketList.tmcNumber] = 1;
	row[mclPacketList.tmcPID] = 15;

	row = *(refLstPacketList->append());
	row[mclPacketList.tmcNumber] = 2;
	row[mclPacketList.tmcPID] = 40;

	/* Add the TreeView's view columns. */
	tvwPacketList->append_column("Number", mclPacketList.tmcNumber);
	tvwPacketList->append_column("PID", mclPacketList.tmcPID);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_btnOpen_clicked()
{
	cout<<"Clicked"<<endl;
}
