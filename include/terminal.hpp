#pragma once
#include <string>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <memory>
#include <ctime>
#include <map>

using path = std::filesystem::path;

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

class CTerm{

    public:
        enum LEVEL{
            INFO,
            SUCCESS,
            ERR
        };

        static CTerm& Instance();
        static void init_logger(std::filesystem::path&& filename, std::filesystem::path&& storagePath);
        static void print(CTerm::LEVEL logLevel, std::string&& text);
        static void print(CTerm::LEVEL logLevel, std::string& text);
        static void tprint(CTerm::LEVEL logLevel, std::string& text);
        static void tprint(CTerm::LEVEL logLevel, std::string&& text);
        static void close(){ CTerm::Instance().outStream->close(); }
        void toString(){ printf("\t-- CTERM INFO --\n\tlogFile[%p]: %s\n\toutStream[%p]\n", &logFile, logFile->string().c_str(), &outStream); }
    private:
        typedef void (*FormatOutputString)(std::string&);
        CTerm(){}
        ~CTerm(){ CTerm::Instance().outStream->close(); }
        bool isInitialized{ false };
        bool isFileLogging{ false };

        std::unique_ptr<path>        logFile{ nullptr };
        std::unique_ptr<std::ofstream>  outStream{ nullptr };

        void info(std::string& text);
        void success(std::string& text);
        void err(std::string& text);

        // std::map<int, FormatOutputString> formatMap { {1, info} };

};  
