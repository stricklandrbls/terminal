
#include "../include/simpleLogger.hpp"

Logger& Logger::Instance(){
	static Logger* _instance = new Logger;
	return *_instance;
}

void Logger::init_logger(std::filesystem::path&& filename, std::filesystem::path&& storagePath){
	Logger::Instance().logFile 	= std::make_unique<path>( storagePath / filename );
	Logger::Instance().outStream = std::make_unique<std::ofstream>( storagePath / filename );
	if( !Logger::Instance().outStream->good() ){
		printf("!! FATAL: Output stream could not be initialized.\n");
		exit(1);
	}
}
void Logger::print(Logger::LEVEL logLevel, std::string&& text){
	Logger::Instance().levelMap[logLevel](text);
	text += "\n";
	printf("[%p] << %s", &(Logger::Instance().outStream), text.c_str());
	*Logger::Instance().outStream << text;
}
void Logger::print(Logger::LEVEL logLevel, std::string& text){
	Logger::Instance().levelMap[logLevel](text);
	text += "\n";
	printf("[%p] << %s", &(Logger::Instance().outStream), text.c_str());
	*Logger::Instance().outStream << text;
}
void Logger::print(Logger::LEVEL logLevel, std::initializer_list<std::string> items){
	std::string tmp{""};
	std::string outputText{""};
	Logger::Instance().levelMap[logLevel](outputText);
	for(auto item : items)
		tmp += item;
	outputText = outputText + tmp + "\n";

	printf("%s", outputText.c_str());
	*Logger::Instance().outStream << outputText;
}
void Logger::tprint(Logger::LEVEL logLevel, std::string&& text){
	Logger::Instance().levelMap[logLevel](text);
	text += "\n";
	printf("%s", text.c_str());
}
void Logger::tprint(Logger::LEVEL logLevel, std::string& text){
	Logger::Instance().levelMap[logLevel](text);
	text += "\n";
	printf("%s", text.c_str());
}
void Logger::tprint(Logger::LEVEL logLevel, std::initializer_list<std::string> items){
	std::string tmp{""};
	std::string outputText{""};
	Logger::Instance().levelMap[logLevel](outputText);
	for(auto item : items)
		tmp += item;
	outputText = outputText + tmp;

	printf("%s\n", outputText.c_str());
}
void Logger::err (std::string& text) { 
	std::string tmp { text };
	std::stringstream output;
	std::time_t timestamp = std::time(nullptr);
	std::tm* formattedTime = std::localtime(&timestamp);
	output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
			<< std::to_string(formattedTime->tm_min)	<< ":"
			<< std::to_string(formattedTime->tm_sec)	<< " [!] ";
	output << text;
	text = output.str();
}
void Logger::info (std::string& text) { 
	std::string tmp { text };
	std::stringstream output;
	std::time_t timestamp = std::time(nullptr);
	std::tm* formattedTime = std::localtime(&timestamp);
	output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
			<< std::to_string(formattedTime->tm_min)	<< ":"
			<< std::to_string(formattedTime->tm_sec)	<< " [ ] ";
	output << text;
	text = output.str();
}

void Logger::success (std::string& text) { 
	std::string tmp { text };
	std::stringstream output;
	std::time_t timestamp = std::time(nullptr);
	std::tm* formattedTime = std::localtime(&timestamp);
	output 	<< std::to_string(formattedTime->tm_hour) 	<< ":"
			<< std::to_string(formattedTime->tm_min)	<< ":"
			<< std::to_string(formattedTime->tm_sec)	<< " [+] ";
	output << text;
	text = output.str();
}


