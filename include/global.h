/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    global.h
 * @brief   The header containing informations used by all
 *          the application.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 16, 2009
 *
 * $Id$
 * $URL$
 *
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <gtkmm.h>
#include <libglademm.h>

/**
 * @brief The application path.
 */
extern std::string applicationPath;

/**
 * @brief The reference pointer to the glade xml configuration.
 */
extern Glib::RefPtr<Gnome::Glade::Xml> rptGlade;

struct Packet_
{
	int num;
	int pid;
};

typedef struct Packet_ Packet;

#endif /* GLOBAL_H_ */
