/*           StreamViewer - A free and open transport stream viewer           */
/* ========================================================================== */
/*    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    */
/* -------------------------------------------------------------------------- */
/**
 * @file    Decoder.h
 * @brief   The header of the decoder class.
 * @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
 * @date    Nov 23, 2009
 *
 * $Id$
 * $URL$
 *
 */

#ifndef DECODER_H_
#define DECODER_H_

class Decoder
{
public:
	/**
	 * @brief The constructor.
	 */
	Decoder();

	/**
	 * @brief The destructor.
	 */
	virtual ~Decoder();

private:
	/**
	 * @brief TBD
	 */
	int packetNumber;

	/**
	 * @brief TBD
	 */
	int pid;
};

#endif /* DECODER_H_ */
