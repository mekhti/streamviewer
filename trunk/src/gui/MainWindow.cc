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
	rptGlade->get_widget("btnOpen", btnOpenDialog);

	btnOpenDialog->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btnOpen_clicked));

	/* Create the Tree model. */
	refLstPacketList = Gtk::ListStore::create(mclPacketList);
	tvwPacketList->set_model(refLstPacketList);

	/* Add the TreeView's view columns. */
	tvwPacketList->append_column("Number", mclPacketList.tmcNumber);
	tvwPacketList->append_column("PID", mclPacketList.tmcPID);
	tvwPacketList->append_column("Description", mclPacketList.tmcDesc);

	Gtk::TreeModel::Row row;
	list<int>::iterator it;

//	for (int i = 345; i < 375; i++)
//	{
//		row = *(refLstPacketList->append());
//		row[mclPacketList.tmcNumber] = i;
//		if ((i == 347) || (i == 357))
//		{
//			row[mclPacketList.tmcPID] = 4;
//			row[mclPacketList.tmcDesc] = "ISO/IEC 13818-3 Audio";
//		}
//		else if (i == 355)
//		{
//			row[mclPacketList.tmcPID] = 10;
//			row[mclPacketList.tmcDesc] = "ISO_639_language_descriptor";
//		}
//		else
//		{
//			row[mclPacketList.tmcPID] = 2;
//			row[mclPacketList.tmcDesc] = "ITU-T Rec. H.262 | ISO/IEC 13818-2 Video | ISO/IEC 11172-2 constr. parameter video stream";
//		}
//	}
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_btnOpen_clicked()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	//Add response buttons the the dialog:
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

	//Add filters, so that only certain file types can be selected:

	Gtk::FileFilter filter_ts;
	filter_ts.set_name("TS files");
	filter_ts.add_pattern("*.ts");
	dialog.add_filter(filter_ts);

	Gtk::FileFilter filter_any;
	filter_any.set_name("Any files");
	filter_any.add_pattern("*");
	dialog.add_filter(filter_any);

	//Show the dialog and wait for a user response:
	int result = dialog.run();

	//Handle the response:
	switch (result) {
	case (Gtk::RESPONSE_OK): {

		//Notice that this is a std::string, not a Glib::ustring.
		std::string filename = dialog.get_filename();
		std::cout << "File selected: " << filename << std::endl;
		list<int> pid_list = decoder.GetNext(1);

		Gtk::TreeModel::Row row;
		list<int>::iterator it;

		for (it = pid_list.begin(); it != pid_list.end(); it++)
		{
			row = *(refLstPacketList->append());
			row[mclPacketList.tmcNumber] = 5;
			row[mclPacketList.tmcPID] = *it;
		}

		break;
	}

	case (Gtk::RESPONSE_CANCEL):
		std::cout << "Cancel clicked." << std::endl;
		break;

	default:
		std::cout << "Unexpected button clicked." << std::endl;
		break;

	}
}
