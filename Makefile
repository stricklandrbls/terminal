C=g++
FLAGS=-Wall -shared -fpic
LOCAL:=0
	
.PHONY: install

all: setup terminal.so

setup: clean 
	@mkdir build

ifeq ($(LOCAL),1)
	@mkdir shared
endif

terminal.so: src/libterminal.cpp
ifeq ($(LOCAL),1)
	$(C) $(FLAGS) -o shared/libterminal.so src/libterminal.cpp
else
	$(C) $(FLAGS) -o build/libterminal.so src/libterminal.cpp
endif


clean:
	@rm -rf build
	@rm -rf shared
	@rm -f *.o
	@rm -f *.so

