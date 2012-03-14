.PHONY = all wii gc linux wii-clean gc-clean linux-clean wii-run gc-run linux-run

all: wii gc linux

run: wii-run

clean: wii-clean gc-clean linux-clean

wii:
		$(MAKE) -f Makefile.wii

wii-clean:
		$(MAKE) -f Makefile.wii clean

wii-run: wii
		$(MAKE) -f Makefile.wii run

gc:
		$(MAKE) -f Makefile.gc

gc-clean:
		$(MAKE) -f Makefile.gc clean

gc-run: gc
		$(MAKE) -f Makefile.gc run
		
linux:
		$(MAKE) -f Makefile.linux

linux-clean:
		$(MAKE) -f Makefile.linux clean
		
linux-run: linux
		$(MAKE) -f Makefile.linux run