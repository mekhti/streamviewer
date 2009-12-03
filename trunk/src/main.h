/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    main.h
 * @brief   The main function.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Dec 2, 2009
 *
 * $Id$
 * $URL$
 *
 */
#ifndef MAIN_H_
#define MAIN_H_

#include "global.h"
#include "Decoder.h"
#include "gui/MainWindow.h"
#include <gtkmm.h>
#include <libglademm/xml.h>

/**
 * @brief The main function.
 */
int main(int argc, char *argv[]);

/**
 * @brief The main window.
 */
MainWindow* winMain;

/**
 * @brief The decoder.
 */
//Decoder decoder;

/**
 * @brief The application path.
 */
std::string applicationPath;

/**
 * @brief The reference pointer to glade.
 */
Glib::RefPtr<Gnome::Glade::Xml> rptGlade;

#endif /* MAIN_H_ */
