/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    MainWindow.h
 * @brief   The header of the main class of the application.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 16, 2009
 *
 * $Id$
 * $URL$
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <libglademm.h>
#include <gtkmm.h>

class MainWindow: public Gtk::Window
{
public:
	/**
	 * @brief The constructor.
	 */
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gnome::Glade::Xml>& glade_xml);

	/**
	 * @brief The destructor.
	 */
	virtual ~MainWindow();

protected:
	/**
	 * @brief TBD
	 */
	void on_btnOpen_clicked();

private:
	class ModelColumnsPacketList: public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumnsPacketList()
		{
			add(tmcNumber);
			add(tmcPID);
		}

		Gtk::TreeModelColumn<unsigned int> tmcNumber;
		Gtk::TreeModelColumn<unsigned int> tmcPID;
	};

	/**
	 * @brief TBD
	 */
	ModelColumnsPacketList mclPacketList;

	/**
	 * @brief TBD
	 */
	Glib::RefPtr<Gtk::ListStore> refLstPacketList;

	/**
	 * @brief TBD
	 */
	Gtk::TreeView tvwPacketList;
};

#endif // MAINWINDOW_H
