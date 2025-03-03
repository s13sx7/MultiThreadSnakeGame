#include "./include/map.h"
#include "./include/snake.h"
#include <thread>
#include <atomic>
#include <iostream>


void InpuThread();
void MoveThread(Snake &snake_, Map &map_);
void reset_input_mode();

std::atomic<bool> game{true};

int main(){
    set_input_mode();
    Snake ydav;
    Map mymap(20,20);
    mymap.spawn_snake(ydav);
    mymap.spawn_fruit();
    mymap.show_map();
    std::thread inp(InpuThread);
    std::thread moveT(MoveThread, std::ref(ydav), std::ref(mymap));
    inp.join();
    moveT.join();
    void reset_input_mode();
    return 0;
}