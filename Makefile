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
	if [ -d "$(PREFIX)lib/terminal" ]; then \
		install -m 644 build/libterminal.so $(PREFIX)lib/terminal; \
	else \
		mkdir $(PREFIX)lib/terminal; \
		install -m 644 build/libterminal.so $(PREFIX)lib/terminal; \
	fi

	if [ -d "$(PREFIX)include/terminal" ]; then \
		install -m 644 include/terminal.hpp $(PREFIX)include/terminal; \
	else \
		mkdir $(PREFIX)include/terminal; \
		install -m 644 include/terminal.hpp $(PREFIX)include/terminal; \
	fi

	export LD_LIBRARY_PATH=/usr/lib/terminal:$$LD_LIBRARY_PATH
