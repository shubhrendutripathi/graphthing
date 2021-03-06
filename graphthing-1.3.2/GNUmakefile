

PACKAGE = graphthing
VERSION = 1.3.2

SUBDIRS = src
prefix = /usr/local

DISTFILES = COPYING CREDITS FeatureLog GNUmakefile.in README TODO \
	graphthing.1.in \
	aclocal.m4 configure configure.in install-sh mkinstalldirs


all:
	@dlist='$(SUBDIRS)' ; \
	for subdir in $$dlist ; do \
		(cd $$subdir && $(MAKE) all) ; \
	done
	@echo "---------------------------------------------------"
	@echo "  GraphThing is now compiled. It can be executed"
	@echo "  by running it directly as:"
	@echo "        src/graphthing"
	@echo "  or by installing it:"
	@echo "        $(MAKE) install"
	@echo "  Installing may require superuser privileges."
	@echo ""
	@echo "  Alternatively, for Mac OSX, create an App bundle:"
	@echo "        $(MAKE) bundle"
	@echo "---------------------------------------------------"

install:
	@dlist='$(SUBDIRS)' ; \
	for subdir in $$dlist ; do \
		(cd $$subdir && $(MAKE) install) ; \
	done
	/usr/bin/install -c -d ${prefix}/share/man/man1/
	/usr/bin/install -c -c -m 644 graphthing.1 ${prefix}/share/man/man1/
	@echo "---------------------------------------------------"
	@echo "  GraphThing is now installed. It can be executed"
	@echo "  by running:"
	@echo "        /usr/local/bin/graphthing"
	@echo "---------------------------------------------------"

# For Mac OSX
bundle:
	@mkdir -p GraphThing.app/Contents/MacOS
	@cp src/graphthing GraphThing.app/Contents/MacOS/GraphThing
	@ls -ld GraphThing.app

# For Win32
zipdir = $(PACKAGE)-$(VERSION)
zip:
	rm -rf $(zipdir)
	mkdir $(zipdir)
	for file in COPYING CREDITS FeatureLog README ; do \
		cat $$file | unix2dos > $(zipdir)/$$file.txt; \
	done
	cp -p src/graphthing.exe $(zipdir)
	strip $(zipdir)/graphthing.exe
	zip -9r $(zipdir)-win32.zip $(zipdir)
	rm -rf $(zipdir)

clean:
	@dlist='$(SUBDIRS)' ; \
	for subdir in $$dlist ; do \
		(cd $$subdir && $(MAKE) clean) ; \
	done

distclean:
	@dlist='$(SUBDIRS)' ; \
	for subdir in $$dlist ; do \
		(cd $$subdir && $(MAKE) distclean) ; \
	done
	rm GNUmakefile graphthing.1

dep:
	@dlist='$(SUBDIRS)' ; \
	for subdir in $$dlist ; do \
		(cd $$subdir && $(MAKE) dep) ; \
	done

distdir = $(PACKAGE)-$(VERSION)
dist:	GNUmakefile
	rm -rf $(distdir)
	mkdir $(distdir)
	chmod 777 $(distdir)
	for file in $(DISTFILES) ; do \
		ln $$file $(distdir) 2>/dev/null || \
			cp -p $$file $(distdir); \
	done
	for subdir in $(SUBDIRS) ; do \
		mkdir $(distdir)/$$subdir || exit 1; \
		chmod 777 $(distdir)/$$subdir; \
		(cd $$subdir && $(MAKE) $@) || exit 1; \
	done
	tar zchf $(distdir).tar.gz $(distdir)
	gunzip -c $(distdir).tar.gz | bzip2 -9 > $(distdir).tar.bz2
	rm -rf $(distdir)
