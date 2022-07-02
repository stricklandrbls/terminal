C=g++
FLAGS=-Wall -shared -fpic
LOCAL:=0
VERSION=0.0
PACKAGE=libterminal_$(VERSION)_amd64
PACKAGELIBDIR=$(PACKAGE)/usr/lib/terminal
PACKAGEINCLUDEDIR=$(PACKAGE)/usr/include/terminal

.PHONY: install

all: setup terminal.so

setup: clean 
	@mkdir build

ifeq ($(LOCAL),1)
	@mkdir shared
endif

deb: setup terminal.so
	@mkdir $(PACKAGE)
	@mkdir $(PACKAGE)/DEBIAN
	@mkdir -p $(PACKAGELIBDIR)
	@mkdir -p $(PACKAGEINCLUDEDIR)
	@cp package/control $(PACKAGE)/DEBIAN/
	@cp package/preinst $(PACKAGE)/DEBIAN/
	@cp package/postinst $(PACKAGE)/DEBIAN/
	@cp include/terminal.hpp $(PACKAGEINCLUDEDIR)
	@cp build/libterminal.so $(PACKAGELIBDIR)
	dpkg-deb --build $(PACKAGE)

terminal.so: src/libterminal.cpp
ifeq ($(LOCAL),1)
	$(C) $(FLAGS) -o shared/libterminal.so src/libterminal.cpp
else
	$(C) $(FLAGS) -o build/libterminal.so src/libterminal.cpp
endif


clean:
	@rm -rf build
	@rm -rf shared
	@rm -rf $(PACKAGE)
	@rm -f *.o
	@rm -f *.so
	@rm -f *.deb

test: setup src/test.cpp
	$(C) -Wall src/test.cpp -o build/$@ -lterminal

install:
	
