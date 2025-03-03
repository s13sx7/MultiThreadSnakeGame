#include "./include/map.h"
#include <iostream>
#include <random>
#include "./include/snake.h"
#include <chrono>
#include <thread>
#include <mutex>
int getRandom(int min, int max);

Map::Map(int a, int b){
    length = a;
    width = b;
    floor = new char *[width];
    for (int i = 0; i < length; i++)
    {
        floor[i] = new char[width];
        std::fill(floor[i], floor[i]+width,'.');
    }
    
};

Map::~Map(){
    for (int j{}; j < width; ++j){
        delete [] floor[j];
    }
    delete [] floor;
}

void Map::show_map(){
    for (int i{}; i < length; ++i){
        std::cout << ' '<< '_';
    }
    std::cout << ' '<<'_'<<'\n';
    for (int i{}; i < length; ++i){
        std::cout << '|' << ' ';
        for (int j{}; j < width; ++j){
            std::cout << floor[i][j] <<' ';
        }
        std::cout << '|' <<std::endl;
    }
    for (int i{}; i < length; ++i){
        std::cout << ' '<< '_';
    }
    std::cout << ' '<<'_'<<'\n';
}
int getRandom(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void Map::spawn_fruit(){
    int a{getRandom(0, length-1)};
    int b{getRandom(0, width-1)};
    while (floor[a][b]=='O' || floor[a][b]=='G'){
        a={getRandom(0, length-1)};
        b={getRandom(0, width-1)};
    }
    floor[a][b]='F';
    friut_on_map=true;
}


void Map::spawn_snake(Snake & snake_){
    snake_.set_head(2,2);
    set_cell(2,2,'G');
}

char Map::get_cell(int length_, int width_){
    return floor[length_][width_];
}

void Map::set_cell(int lenght_, int width_, char ch){
    floor[lenght_][width_] = ch;
}

int Map::get_width()const{
    return width;
}

int Map::get_length() const{
    return length;
}