#include "../include/simpleLogger.hpp"

int main(){
    // Logger::init_logger("Test.log", "./");
    // Logger::print(Logger::LEVEL::SUCCESS, "This worked!");
    // Logger::print(Logger::LEVEL::SUCCESS, "This might not work!");
    Logger::tprint(Logger::LEVEL::INFO, {"Test ", "This ", std::to_string(10)});
    Logger::tprint(Logger::LEVEL::INFO, "Test this too");
    // Logger::close();
    return 0;
}
