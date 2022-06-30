#include <terminal/terminal.hpp>

int main(){
    printf("Terminal created! [%p]\n", &(Terminal::logger));
    Terminal::logger.init("test.log", "/tmp");
    Terminal::log(Terminal::success, "This worked!", false);
    return 0;
}
