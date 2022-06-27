#include <string>
#include <stdio.h>
#include "../include/terminal.hpp"

namespace Terminal{
	void err      (std::string& text)         { printf("[!] %s\n", text.c_str()); }
	void info     (std::string& text)         { printf("[ ] %s\n", text.c_str()); }
	void success  (std::string& text)         { printf("[+] %s\n", text.c_str()); }

	void print(void (*print) (std::string&), std::string&& text)    { print(text); } 
	void print(void (*print) (std::string&), std::string& text)     { print(text); } 
} 
