#ifndef MAP_H
#define MAP_H
class Snake;
class Map{
    private:
        int length;
        int width;
        char **floor;
        bool friut_on_map{true};
    public:
        Map(int = 10, int = 10);
        void spawn_fruit();
        void show_map();
        void spawn_snake(Snake &);
        char get_cell(int, int);
        void set_cell(int, int, char);
        int get_width() const;
        int get_length() const;
        bool & get_friut_on_map(){return friut_on_map;}
        ~Map();
};

#endif