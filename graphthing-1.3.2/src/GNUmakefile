PACKAGE = graphthing
VERSION = 1.3.2

subdir = src
prefix = /usr/local

DISTFILES = GNUmakefile.in config.h.in depend.1 *.cc *.h *.hh *.y *.l *.gt \
		phrases.lang *.sh *.xpm

CFLAGS = -g -O2 
CXXFLAGS = -g -O2  \
		-I/usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread
LDFLAGS =  
INSTALL = /usr/bin/install -c

LIBS = -lm  -L/usr/lib/x86_64-linux-gnu -pthread   -lwx_gtk2u_xrc-3.0 -lwx_gtk2u_html-3.0 -lwx_gtk2u_qa-3.0 -lwx_gtk2u_adv-3.0 -lwx_gtk2u_core-3.0 -lwx_baseu_xml-3.0 -lwx_baseu_net-3.0 -lwx_baseu-3.0 
#LIBS = -lm  -L/usr/lib/x86_64-linux-gnu -pthread   -lwx_gtk2u_xrc-3.0 -lwx_gtk2u_html-3.0 -lwx_gtk2u_qa-3.0 -lwx_gtk2u_adv-3.0 -lwx_gtk2u_core-3.0 -lwx_baseu_xml-3.0 -lwx_baseu_net-3.0 -lwx_baseu-3.0  -lefence

PARSERS = gt. lang.

OBJS = aboutbox.o canvas.o edge.o exporter.o factory.o fancyfileselection.o \
       graph.o graph2.o gui.o gui_cb.o main.o math.o matrix.o matrixdialog.o \
	paramdialog.o polynomial.o undo.o vertex.o \
	lang.o

TEST_OBJS = edge.o factory.o graph.o graph2.o math.o matrix.o polynomial.o \
		vertex.o
CHROM_OBJS = edge.o factory.o graph.o graph2.o math.o matrix.o polynomial.o \
		vertex.o

BISON_OBJS = $(PARSERS:.=-bison.tab.o)
FLEX_OBJS = $(PARSERS:.=-flex.yy.o)
ALL_OBJS = $(OBJS) $(BISON_OBJS) $(FLEX_OBJS)

PROGNAME = graphthing

all:		$(PROGNAME) $(addsuffix ,)

install:
	/usr/bin/install -c -d /usr/local/bin/
	/usr/bin/install -c -s -m 755 $(PROGNAME) /usr/local/bin/

clean:
	rm -f $(ALL_OBJS) unit_test.o chrom.o
	rm -f $(BISON_OBJS:.o=.cc) $(BISON_OBJS:.o=.hh)
	rm -f $(FLEX_OBJS:.o=.cc)
	rm -f $(PROGNAME) unit_test chrom
	rm -f core gmon.out graphthing.exe.stackdump

distclean:	clean
	rm -f config.h GNUmakefile

$(PROGNAME):	$(ALL_OBJS) $(EXTRA_LIBS)
	@echo "Linking $@"
	@g++ $(LDFLAGS) $^ $(LIBS) -o $@

unit_test:	unit_test.o $(TEST_OBJS) $(EXTRA_LIBS)
	@echo "Linking $@"
	@g++ $(LDFLAGS) $^ $(LIBS) -o $@
chrom:	chrom.o $(CHROM_OBJS) $(EXTRA_LIBS)
	@echo "Linking $@"
	@g++ $(LDFLAGS) $^ $(LIBS) -o $@

# Have faith that bison and flex produce good code
%.tab.o : %.tab.cc
	@echo "$< -> $@"
	@g++ -g -O2 -I/usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread -O -g -c $< -o $@
%.yy.o : %.yy.c
	@echo "$< -> $@"
	@g++ -g -O2 -I/usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread -O -g -c $< -o $@

%-bison.tab.cc : %-bison.y
	@echo "$< -> $@"
	@bison -y -d -p yy_$*_ -o $@ $<
%-flex.yy.c : %-flex.l
	@echo "$< -> $@"
	@flex -Pyy_$*_ -o$@ $<

lang.cc : phrases.h
phrases.h : phrases.lang
	@./init-phrases.sh

#%.o : %.c
#	@echo "$< -> $@"
#	@gcc $(CFLAGS) -c $< -o $@
%.o : %.cc
	@echo "$< -> $@"
	@g++ $(CXXFLAGS) -c $< -o $@



################
# DEPENDENCIES #
################

dep:
	@echo -n "Generating dependancies... "
	@g++ -MM -I/usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread $(OBJS:.o=.cc) unit_test.cc \
		| sed "s#[ ][-A-Za-z0-9./]*/wx/[-A-Za-z0-9./]*\.h##g" \
		| grep -v "^[ ]*\\\\$$" > depend.1
	@echo "done!"

ifeq (depend.1, $(wildcard depend.1))
include depend.1
endif



distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist:	GNUmakefile $(DISTFILES)
	for file in $(DISTFILES) ; do \
		ln $$file $(distdir) 2>/dev/null || \
			cp -p $$file $(distdir) ; \
	done
	mkdir $(distdir)/flags
	for file in flags/*.xpm ; do \
		ln $$file $(distdir)/flags 2>/dev/null || \
			cp -p $$file $(distdir)/flags ; \
	done
