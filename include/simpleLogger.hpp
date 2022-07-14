#pragma once
#include <string>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <memory>
#include <ctime>
#include <map>
#include <functional>
#include <initializer_list>
#include <iostream>

using path = std::filesystem::path;

class Logger{

    public:
        enum LEVEL{
            INFO,
            SUCCESS,
            ERR
        };

        static Logger& Instance();

        static void init_logger (std::filesystem::path&& filename, std::filesystem::path&& storagePath);
        static void print       (Logger::LEVEL logLevel, std::string&& text);
        static void print       (Logger::LEVEL logLevel, std::string& text);
        static void print       (Logger::LEVEL logLevel, std::initializer_list<std::string> texts);
        static void tprint      (Logger::LEVEL logLevel, std::string& text);
        static void tprint      (Logger::LEVEL logLevel, std::string&& text);
        static void tprint      (Logger::LEVEL logLevel, std::initializer_list<std::string> texts);

        // static void hexdump     (Logger::LEVEL logLevel, Object obj);
        static void close() { Logger::Instance().outStream->close(); }
        void toString()     { printf("\t-- CTERM INFO --\n\tlogFile[%p]: %s\n\toutStream[%p]\n", &logFile, logFile->string().c_str(), &outStream); }
    private:

        Logger(){}
        ~Logger(){ Logger::Instance().outStream->close(); }

        bool isInitialized{ false };
        bool isFileLogging{ false };

        std::unique_ptr<path>           logFile{ nullptr };
        std::unique_ptr<std::ofstream>  outStream{ nullptr };

        static void info        (std::string& text);
        static void success     (std::string& text);
        static void err         (std::string& text);

        std::map<int, std::function<void(std::string&)>> levelMap{
            { Logger::LEVEL::INFO, info },
            { Logger::LEVEL::SUCCESS, success },
            { Logger::LEVEL::ERR, err}
        };
};  
