#pragma once
#include <string>
#include <stdio.h>

namespace Terminal{
    void err(std::string& text);
    void info(std::string& text);
    void success(std::string& text);
    void print(void (*print) (std::string&), std::string&& text);
    void print(void (*print) (std::string&), std::string& text);
};
