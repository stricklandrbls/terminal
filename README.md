# SimpleLogger Library

## Overview
The simepleLogger library is a shared object library to add to any software development program so simple logging functionality.

simpleLogger has two different methods of printing output:
1. Terminal printouts
2. Terminal & log file printouts.

## Installation
Makefile only configures simpleLogger for amd64(x86_64) architecture CPUs. If you wish to change that, edit the makefile.
1. `make deb`
2. `sudo apt install -f ./libsimpleLogger_(VERSION)-(RELEASE)_amd64.deb`

## Adding to source
In order to use the simpleLogger library, simple include it's installed header file & link the library during compilation.
### C++
```C++
#include <simpleLogger/simpleLogger.hpp>
```
### Makefile
```Makefile
g++ main.cpp -o <output_bin> -lsimpleLogger
```

## Usage
simpleLogger usage is quite simple. The only instatiation needed is the log filename and output location.
```C++
#include <simpleLogger/simpleLogger.hpp>

int main(){
    Logger::Instance().init_logger("<filename>", "<path>");
}
```
The singleton logger instance needs to be called in order to initialize. Subsequent simpleLogger function calls automatically call the instance.

**Print / Logging Functions**
To print log messages to the terminal, and/or log file, the following functions can be used:
| Function | Description | Parameters  |
| --- | --- | --- |
| print | Prints a message to the terminal AND logs the message to the log file | `Logger::LEVEL` & `std::string&(&)` |
| tprint | Prints a message to the terminal ONLY | `Logger::LEVEL` & ( `std::string&(&)` OR `{std::string&(&) 1, ... , std::string&(&) n}` )

**Logger::LEVEL**
| Level | Description |
| --- | --- |
| INFO | Holds function pointer to format the beginning of the log message w/ `00:00:00 [ ]` |
| ERR | Holds function pointer to format the beginning of the log message w/ `00:00:00 [!]` |
| SUCCESS | Holds function pointer to format the beginning of the log message w/ `00:00:00 [+]` |
**Example**
```C++
#include <simpleLogger/simpleLogger.hpp>

int main(){
    Logger::Instance().init_logger("<filename>", "<path>");
    Logger::print(Logger::LEVEL::INFO, {"Test ", "This ", std::to_string(10)});
    Logger::print(Logger::LEVEL::INFO, "Test this too");
}
```
This would log the following messages to the terminal AND log file:
```
00:00:00 [ ] Test This 10
00:00:00 [ ] Test this too
```