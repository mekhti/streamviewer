CXX = g++
RM  = rm -f

ROOT_PATH    = .
BINARY_PATH  = $(ROOT_PATH)/bin
INCLUDE_PATH = $(ROOT_PATH)/include
LIBRARY_PATH = $(ROOT_PATH)/lib
OBJECT_PATH  = $(ROOT_PATH)/obj
SOURCE_PATH  = $(ROOT_PATH)/src

# pkg-config --cflags --libs gtkmm-2.4 libglademm-2.4

CFLAGS = -Wall \
         -D_REENTRANT \
         -I/usr/include/gtkmm-2.4 \
         -I/usr/lib/gtkmm-2.4/include \
         -I/usr/include/glibmm-2.4 \
         -I/usr/lib/glibmm-2.4/include \
         -I/usr/include/gdkmm-2.4 \
         -I/usr/lib/gdkmm-2.4/include \
         -I/usr/include/pangomm-1.4 \
         -I/usr/include/atkmm-1.6 \
         -I/usr/include/gtk-2.0 \
         -I/usr/include/sigc++-2.0 \
         -I/usr/lib/sigc++-2.0/include \
         -I/usr/include/glib-2.0 \
         -I/usr/lib/glib-2.0/include \
         -I/usr/lib/gtk-2.0/include \
         -I/usr/include/cairomm-1.0 \
         -I/usr/include/pango-1.0 \
         -I/usr/include/cairo \
         -I/usr/include/freetype2 \
         -I/usr/include/directfb \
         -I/usr/include/libpng12 \
         -I/usr/include/pixman-1 \
         -I/usr/include/atk-1.0 \
         -I/usr/include/libglademm-2.4 \
         -I/usr/lib/libglademm-2.4/include \
         -I/usr/include/libglade-2.0 \
         -I/usr/include/libxml2 \
         -I/usr/include/giomm-2.4 \
         -I/usr/lib/giomm-2.4/include \
         -I/usr/include/gtk-unix-print-2.0

LIBS   = -lglademm-2.4 \
         -lgtkmm-2.4 \
         -lglade-2.0 \
         -lgdkmm-2.4 \
         -latkmm-1.6 \
         -lpangomm-1.4 \
         -lcairomm-1.0 \
         -lglibmm-2.4 \
         -lsigc-2.0 \
         -lgtk-x11-2.0 \
         -lxml2 \
         -lgdk-x11-2.0 \
         -latk-1.0 \
         -lgdk_pixbuf-2.0 \
         -lm \
         -lpangocairo-1.0 \
         -lpango-1.0 \
         -lcairo \
         -lgobject-2.0 \
         -lgmodule-2.0 \
         -ldl \
         -lglib-2.0 \
         -lgiomm-2.4 \
         -lpangoft2-1.0 \
         -lgio-2.0 \
         -lfreetype \
         -lfontconfig

SOURCES = main.cc \
          gui/MainWindow.cc

OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

SOURCES_LIST = $(addprefix $(SOURCE_PATH)/, $(SOURCES))
OBJECTS_LIST = $(addprefix $(OBJECT_PATH)/, $(OBJECTS))

EXECUTABLE = streamviewer

all: header $(EXECUTABLE)

header:
	@echo ""
	@echo "================================================================"
	@echo "    StreamViewer - A free and open transport stream analyser    "
	@echo "================================================================"
	@echo ""

$(EXECUTABLE): $(OBJECTS_LIST)
	@echo "Building $(EXECUTABLE)..."
	@echo "----------------------------------------------------------------"
	$(CXX) $(OBJECTS_LIST) $(LIBS) -o $(BINARY_PATH)/streamviewer
	@echo ""
	@echo "Done."
	@echo ""

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cc
	@echo "Compiling $<..."
	@echo "----------------------------------------------------------------"
	$(CXX) $(CFLAGS) -I$(INCLUDE_PATH) $< -c -o $@
	@echo ""

clean: header
	@echo "Clean objects and executable..."
	@echo "----------------------------------------------------------------"
	-$(RM) $(OBJECTS_LIST) $(BINARY_PATH)/$(EXECUTABLE)
	@echo ""
	@echo "Done."
	@echo ""
