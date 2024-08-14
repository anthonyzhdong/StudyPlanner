#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
// macos /linux
int getTerminalWidth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int main() {
    int width = getTerminalWidth();
    std::cout << "The current terminal width is: " << width << " characters." << std::endl;
    
    // Demonstrate the width by printing a line of characters
    std::cout << std::string(width, '-') << std::endl;
    
    return 0;
}
// #include <windows.h>

// int getTerminalWidth() {
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//     return csbi.srWindow.Right - csbi.srWindow.Left + 1;
// }
