TAG := $(shell git describe --always --dirty || echo UNKNOWN)
VERSION := $(shell echo $(TAG:v%=%) | cut -d- -f1)
MAJOR := $(shell echo $(VERSION) | cut -d. -f1)

default: libcrucible.so.$(VERSION)

OBJS = \
	crc64.o \
	chatter.o \
	error.o \
	extentwalker.o \
	fd.o \
	fs.o \
	ntoa.o \
	path.o \
	process.o \
	string.o \
	time.o \
	uuid.o \
	.version.o \

include ../makeflags

depends.mk: *.cc
	for x in *.cc; do $(CXX) $(CXXFLAGS) -M "$$x"; done >> depends.mk.new
	mv -fv depends.mk.new depends.mk

.version.cc: Makefile ../makeflags *.cc ../include/crucible/*.h
	echo "namespace crucible { const char *VERSION = \"$(TAG)\"; }" > .version.new.cc
	mv -f .version.new.cc .version.cc

-include depends.mk

install: libcrucible.so.$(VERSION)
	install -Dm644 libcrucible.so.$(VERSION) $(DESTDIR)$(USRLIB_PREFIX)/libcrucible.so.$(VERSION)

%.o: %.cc ../include/crucible/%.h
	$(CXX) $(CXXFLAGS) -fPIC -o $@ -c $<

libcrucible.so.$(VERSION): $(OBJS) Makefile
	$(CXX) $(LDFLAGS) -fPIC -o $@ $(OBJS) -shared -Wl,-soname,$(@:so.$(VERSION)=so.$(MAJOR)) -luuid
	ln -snf $@ $(@:so.$(VERSION)=so.$(MAJOR))
	ln -snf $@ $(@:so.$(VERSION)=so)
