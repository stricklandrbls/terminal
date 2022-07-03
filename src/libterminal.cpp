
#include "../include/terminal.hpp"
#include <sstream>

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
		output << std::asctime(std::localtime(&timestamp));
		output << text;
		text = output.str().replace(output.str().find('\n'), 1, " [!] ");
	}

	void info     (std::string& text) { 
		std::string tmp { text };
		std::stringstream output;
		timestamp = std::time(nullptr);
		output << std::asctime(std::localtime(&timestamp));
		output << text;
		text = output.str().replace(output.str().find('\n'), 1, " [ ] ");
	}

	void success  (std::string& text) { 
		std::string tmp { text };
		std::stringstream output;
		timestamp = std::time(nullptr);
		formattedTime = std::localtime(&timestamp);
		output << std::to_string(formattedTime->tm_hour) << std::to_string(formattedTime->tm_min);
		output << text;
		// text = output.str().replace(output.str().find('\n'), 1, " [+] ");
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

