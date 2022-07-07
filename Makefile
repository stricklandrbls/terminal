C=g++
FLAGS=-Wall -shared -fpic
LOCAL:=0
VERSION=1.0
RELEASE=1
PACKAGE=libsimpleLogger_$(VERSION)-$(RELEASE)_amd64
PACKAGELIBDIR=$(PACKAGE)/usr/lib/simpleLogger
PACKAGEINCLUDEDIR=$(PACKAGE)/usr/include/simpleLogger

.PHONY: install

all: setup simpleLogger.so

setup: clean 
	@mkdir build

ifeq ($(LOCAL),1)
	@mkdir shared
endif

deb: setup simpleLogger.so
	@mkdir $(PACKAGE)
	@mkdir $(PACKAGE)/DEBIAN
	@mkdir -p $(PACKAGELIBDIR)
	@mkdir -p $(PACKAGEINCLUDEDIR)
	@cp package/control $(PACKAGE)/DEBIAN/
	@cp package/preinst $(PACKAGE)/DEBIAN/
	@cp package/postinst $(PACKAGE)/DEBIAN/
	@cp include/simpleLogger.hpp $(PACKAGEINCLUDEDIR)
	@cp build/libsimpleLogger.so $(PACKAGELIBDIR)
	dpkg-deb --build $(PACKAGE)

simpleLogger.so: src/libsimpleLogger.cpp
ifeq ($(LOCAL),1)
	$(C) $(FLAGS) -o shared/libsimpleLogger.so src/libsimpleLogger.cpp
else
	$(C) $(FLAGS) -o build/libsimpleLogger.so src/libsimpleLogger.cpp
endif


clean:
	@rm -rf build
	@rm -rf shared
	@rm -rf $(PACKAGE)
	@rm -f *.o
	@rm -f *.so
	@rm -f *.deb
	@rm -f *.log
	
test: setup src/test.cpp
	$(C) -Wall src/libsimpleLogger.cpp src/test.cpp -o build/$@

install:
	
