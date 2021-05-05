#pragma once
#include "Board.hpp"
#include "City.hpp"



namespace pandemic{
    
    class Player{
        protected:
            Board& board;
            City city;
            std::string role_of;

        public:
            Player(Board& b, City c, string r) : board(b), city(c), role_of(r){}
            virtual Player& take_card(City city);
            virtual Player& drive(City city);
            virtual Player& fly_direct(City city);
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City city);
            std::string role(){return role_of;}
        };

};