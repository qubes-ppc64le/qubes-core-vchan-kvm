PREFIX ?= /usr
LIBDIR ?= $(PREFIX)/lib
INCLUDEDIR ?= $(PREFIX)/include

help:
	@echo "make all                   -- build binaries"
	@echo "make clean                 -- cleanup"

all:
	$(MAKE) -C u2mfn
	$(MAKE) -C vchan -f Makefile

install:
	#### qubes-libvchan-kvm
	install -D vchan/libvchan-kvm.so ${DESTDIR}$(LIBDIR)/libvchan-kvm.so
	install -D u2mfn/libu2mfn.so ${DESTDIR}$(LIBDIR)/libu2mfn.so

	# qubes-libvchan-kvm-devel
	install -D -m 0644 vchan/libvchan.h ${DESTDIR}$(INCLUDEDIR)/vchan-kvm/libvchan.h
	install -D -m 0644 vchan/vchan-kvm.pc ${DESTDIR}$(LIBDIR)/pkgconfig/vchan-kvm.pc
	install -D -m 0644 u2mfn/u2mfnlib.h ${DESTDIR}$(INCLUDEDIR)/u2mfnlib.h
	install -D -m 0644 u2mfn/u2mfn-kernel.h ${DESTDIR}$(INCLUDEDIR)/u2mfn-kernel.h

clean:
	make -C u2mfn clean
	make -C vchan -f Makefile clean
