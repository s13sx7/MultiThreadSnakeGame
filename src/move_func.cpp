#include "./include/snake.h"
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

struct termios old_settings;

void set_input_mode(){
    struct termios settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    settings = old_settings;
    settings.c_lflag &= ~ICANON;
    settings.c_lflag &= ~ECHO; 
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
}

char get_ch(){
    char ch;
    read(STDIN_FILENO, &ch, 1);
    return ch;
}

void reset_input_mode(){
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
}