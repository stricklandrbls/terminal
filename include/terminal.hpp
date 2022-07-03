#pragma once
#include <string>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <memory>
#include <ctime>

class FileLogger{
	public:
		FileLogger(std::string& filename, std::filesystem::path& storagePath): storagePath{ storagePath }, filename{ filename }{}
		FileLogger(std::string&& filename, std::filesystem::path&& storagePath): storagePath{ storagePath }, filename{ filename }{}
		~FileLogger(){}
        
	private:
		std::filesystem::path 	storagePath;
		std::string 	filename;
		std::ofstream 	log;
};

namespace Terminal{
    void err(std::string& text);
    void info(std::string& text);
    void success(std::string& text);
    void print(void (*print) (std::string&), std::string&& text);
    void print(void (*print) (std::string&), std::string& text);
    void tprint(void (*print) (std::string&), std::string& text);
    void tprint(void (*print) (std::string&), std::string&& text);
    void init_logger(std::string&& filename, std::filesystem::path&& storagePath);
};
