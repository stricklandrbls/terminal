#include "../include/terminal.hpp"

int main(){
    // Terminal::init_logger("test.log", "/tmp");
    // Terminal::print(Terminal::success, "This worked!");
    // Terminal::print(Terminal::err, "This did not work!");
    // Terminal::print(Terminal::info, " -- End of log --");
    CTerm::init_logger("Test.log", "./");
    CTerm::print(CTerm::LEVEL::SUCCESS, "This worked!");
    CTerm::print(CTerm::LEVEL::SUCCESS, "This might not work!");
    CTerm::close();
    return 0;
}
