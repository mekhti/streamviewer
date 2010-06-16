##           StreamViewer - A free and open transport stream viewer           ##
## ========================================================================== ##
##    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License    ##
## -------------------------------------------------------------------------- ##
##
## @file    Makefile
## @brief   The project makefile.
## @author  Paulo Flabiano Smorigo <pfsmorigo@gmail.com>
## @date    Nov 16, 2009
##
## $Id$
## $URL$
##
 
#############################   C o m m a n d s   #############################

CXX = g++
RM  = rm -f

################################   P a t h s   ################################

ROOT_PATH    = .
BINARY_PATH  = $(ROOT_PATH)/bin
DEBUG_PATH   = $(ROOT_PATH)/debug
INCLUDE_PATH = $(ROOT_PATH)/include
LIBRARY_PATH = $(ROOT_PATH)/lib
SOURCE_PATH  = $(ROOT_PATH)/src

##################   C   F l a g s   &   L i b r a r i e s   ##################

CFLAGS = -Wall $(shell pkg-config --cflags gtkmm-2.4 libglademm-2.4)
LIBS   = $(shell pkg-config --libs gtkmm-2.4 libglademm-2.4)

##############################   S o u r c e s   ##############################

SOURCES = main.cc \
          Decoder.cc \
          gui/MainWindow.cc

##############################   O b j e c t s   ##############################

OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))
DEBUG_OBJECTS = $(addprefix $(DEBUG_PATH)/, $(OBJECTS))

###############################################################################
##                               T a r g e t s                               ##
###############################################################################

EXECUTABLE = streamviewer

all: header clean $(EXECUTABLE)

header:
	@echo ""
	@echo "           StreamViewer - A free and open transport stream viewer          "
	@echo " =========================================================================="
	@echo "    Copyright © 2009 - Paulo Flabiano Smorigo - Under GNU GPL v2 License   "
	@echo " --------------------------------------------------------------------------"
	@echo ""

$(EXECUTABLE): $(DEBUG_OBJECTS)
	@echo "Building $(EXECUTABLE)..."
	@echo "----------------------------------------------------------------"
	$(CXX) -g3 $(DEBUG_OBJECTS) $(LIBS) -o $(BINARY_PATH)/streamviewer
	@echo ""
	@echo "Done."
	@echo ""

$(DEBUG_PATH)/%.o: $(SOURCE_PATH)/%.cc
	@echo "Compiling $<..."
	@echo "----------------------------------------------------------------"
	$(CXX) -g3 $(CFLAGS) -I$(INCLUDE_PATH) $< -c -o $@
	@echo ""

clean: header
	@echo "Clean objects and executable..."
	@echo "----------------------------------------------------------------"
	-$(RM) $(DEBUG_OBJECTS) $(BINARY_PATH)/$(EXECUTABLE)
	@echo ""
	@echo "Done."
	@echo ""
