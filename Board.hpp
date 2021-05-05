#pragma once
#include <set>
#include <iostream>
#include <map>
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {
    class Board {
        private:
            Color color=Blue;
            map<City,int>disease_lvl;
        friend class Player;
        public:
            Board();
            
            bool is_clean();
            void remove_cures();
            void build(City city);
            set<City> research_station;
            bool cure_black=false;
            bool cure_blue=false;
            bool cure_red=false;
            bool cure_yellow=false;
            
           
            int& operator[](City city);
            friend ostream& operator<<(ostream& out, const Board& board);
    };
}
