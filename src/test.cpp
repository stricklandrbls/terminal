#include "../include/simpleLogger.hpp"

int main(){
    Logger::init_logger("Test.log", "./");
    Logger::print(Logger::LEVEL::SUCCESS, "This worked!");
    Logger::print(Logger::LEVEL::SUCCESS, "This might not work!");
    Logger::close();
    return 0;
}
