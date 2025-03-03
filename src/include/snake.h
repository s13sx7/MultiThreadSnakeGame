#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <atomic>
#include <mutex>
#include <deque>


class Map;

class Snake
{
private:
    std::mutex snakeM;
    std::deque<std::pair<int,int>> body;
public:
    Snake(){};
    bool move(Map &,char);
    void set_head(int , int);
    std::pair<int, int> gethead();
    ~Snake(){};
};
void set_input_mode();
char get_ch();

#endif