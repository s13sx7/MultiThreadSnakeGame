#include "./include/snake.h"
#include "./include/map.h"
#include <thread>
#include <chrono>

extern std::atomic<bool> game;

char direction{'d'};
void InpuThread(){
    set_input_mode();

    while(game){
        char input = get_ch();
        if (input == 'w' || input == 'a' || input == 's' || input == 'd'){
            direction = input;
        }
    }

}

void MoveThread(Snake &snake_, Map &map_){
    while(game){
        game.store(snake_.move(map_,direction));
        if(!map_.get_friut_on_map()){
            map_.spawn_fruit();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}