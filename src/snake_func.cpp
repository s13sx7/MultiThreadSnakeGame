#include "./include/snake.h"
#include "./include/map.h"
#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>
void Snake::set_head(int i,int j){body.push_front({i,j});std::cout<<body[0].first<<' '<<body[0].second;}
std::pair<int, int> Snake::gethead(){
    return body[0];
}

bool Snake::move(Map & map_, char key){
    switch (key){
        
    case 'w':
        system("clear");
        body.push_front({body[0].first-1, body[0].second});
        if(body[0].first < 0 || map_.get_cell(body[0].first, body[0].second)=='O'){
            return 0;
            break;
        }
        if (map_.get_cell(body[0].first, body[0].second)=='F'){
            map_.get_friut_on_map()=false;
        }
        if (map_.get_cell(body[0].first, body[0].second)!='F'){
            map_.set_cell(body.back().first, body.back().second,'.');
            body.pop_back();
        }
        map_.set_cell(body[0].first,body[0].second,'G');
        if(body.size()>0){
        for (size_t i{1}; i < body.size(); ++i){
            map_.set_cell(body[i].first,body[i].second,'O');
            }
        }
        map_.show_map();
        return 1;
        break;
    
    case 'a':
        system("clear");
        body.push_front({body[0].first, body[0].second-1});
        if(body[0].second <0 || map_.get_cell(body[0].first, body[0].second)=='O'){
            std::cout<<"game over";
            return 0;
            break;
        }
        if (map_.get_cell(body[0].first, body[0].second)=='F'){
            map_.get_friut_on_map()=false;
        }
        if (map_.get_cell(body[0].first, body[0].second)!='F'){
            map_.set_cell(body.back().first, body.back().second,'.');
            body.pop_back();
        }
        map_.set_cell(body[0].first,body[0].second,'G');
        if(body.size()>0){
        for (size_t i{1}; i < body.size(); ++i){
            map_.set_cell(body[i].first,body[i].second,'O');
            }
        }
        map_.show_map();
        return 1;
        break;

    case 's':
        system("clear");
        body.push_front({body[0].first+1, body[0].second});
        if(body[0].second >=map_.get_length() || map_.get_cell(body[0].first, body[0].second)=='O'){
            std::cout<<"game over";
            return 0;
            break;
        }
        if (map_.get_cell(body[0].first, body[0].second)=='F'){
            map_.get_friut_on_map()=false;
        }
        if (map_.get_cell(body[0].first, body[0].second)!='F'){
            map_.set_cell(body.back().first, body.back().second,'.');
            body.pop_back();
        }
        map_.set_cell(body[0].first,body[0].second,'G');
        if(body.size()>0){
        for (size_t i{1}; i < body.size(); ++i){
            map_.set_cell(body[i].first,body[i].second,'O');
            }
        }
        map_.show_map();
        return 1;
        break;

    case 'd':
        system("clear");
        body.push_front({body[0].first, body[0].second+1});
        if(body[0].second >=map_.get_width() || map_.get_cell(body[0].first, body[0].second)=='O'){
            std::cout<<"game over";
            return 0;
            break;
        }
        if (map_.get_cell(body[0].first, body[0].second)=='F'){
            map_.get_friut_on_map()=false;
        }
        if (map_.get_cell(body[0].first, body[0].second)!='F'){
            map_.set_cell(body.back().first, body.back().second,'.');
            body.pop_back();
        }
        map_.set_cell(body[0].first,body[0].second,'G');
        if(body.size()>0){
        for (size_t i{1}; i < body.size(); ++i){
            map_.set_cell(body[i].first,body[i].second,'O');
            }
        }
        map_.show_map();
        return 1;
        break;
    }
}