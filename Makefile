C=g++
FLAGS=-Wall -shared -fpic 

ifeq ($(PREFIX),)
		PREFIX:=/usr/
endif
	
.PHONY: install

all: terminal.so
	
terminal.so: src/libterminal.cpp
	mkdir build 
	$(C) $(FLAGS) -o build/libterminal.so src/libterminal.cpp

clean:
	rm -rf build

install: terminal.so
	install -d terminal $(PREFIX)lib/
	install -d terminal $(PREFIX)include/
	install -m 644 build/libterminal.so $(PREFIX)lib/terminal/
	install -m 644 include/terminal.hpp $(PREFIX)include/terminal/ 	
	export LD_LIBRARY_PATH=/usr/lib/terminal:$LD_LIBRARY_PATH