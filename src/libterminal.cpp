
#include "../include/terminal.hpp"
#include <sstream>

CTerm& CTerm::Instance(){
	static CTerm* _instance = new CTerm;
	printf("Instance mem address: %p[%d]\n", _instance, _instance->isInitialized);
	return *_instance;
}

void CTerm::init_logger(std::filesystem::path&& filename, std::filesystem::path&& storagePath){
	CTerm::Instance().logFile 	= std::make_unique<path>( storagePath / filename );
	CTerm::Instance().outStream = std::make_unique<std::ofstream>( storagePath / filename );
	if( !CTerm::Instance().outStream->good() ){
		printf("!! FATAL: Output stream could not be initialized.\n");
		exit(1);
	}
}
void CTerm::print(CTerm::LEVEL logLevel, std::string&& text){
	printf("[%p] << %s\n", &(CTerm::Instance().outStream), text.c_str());
	*CTerm::Instance().outStream << text;
}

namespace Terminal{

    std::time_t     timestamp;
	std::tm* 		formattedTime;
	std::unique_ptr<FileLogger> logger;

	void init_logger(std::string&& filename, std::filesystem::path&& storagePath){
		if( logger != nullptr ){
			Terminal::print(Terminal::err, "Logger is already initialized!");
		}
		else{
			logger = std::make_unique<FileLogger>(filename, storagePath);
			Terminal::print(Terminal::success, "FileLogger initialized!");
		}
	}

	void err (std::string& text) { 
		std::string tmp { text };
		std::stringstream output;
		timestamp = std::time(nullptr);
		formattedTime = std::localtime(&timestamp);
		output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
				<< std::to_string(formattedTime->tm_min)	<< ":"
				<< std::to_string(formattedTime->tm_sec)	<< " [!] ";
		output << text;
		text = output.str();
	}

	void info     (std::string& text) { 
		std::string tmp { text };
		std::stringstream output;
		timestamp = std::time(nullptr);
		formattedTime = std::localtime(&timestamp);
		output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
				<< std::to_string(formattedTime->tm_min)	<< ":"
				<< std::to_string(formattedTime->tm_sec)	<< " [ ] ";
		output << text;
		text = output.str();
	}

	void success  (std::string& text) { 
		std::string tmp { text };
		std::stringstream output;
		timestamp = std::time(nullptr);
		formattedTime = std::localtime(&timestamp);
		output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
				<< std::to_string(formattedTime->tm_min)	<< ":"
				<< std::to_string(formattedTime->tm_sec)	<< " [+] ";
		output << text;
		text = output.str();
	}

	void print(void (*format) (std::string&), std::string& text) { 
		format(text);
		printf("%s\n", text.c_str());

	} 

	void print(void (*format) (std::string&), std::string&& text) { 
		format(text);
		printf("%s\n", text.c_str());
	} 


} 

