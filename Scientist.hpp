#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class Scientist : public Player{
        int number ;

        public:
            Scientist(Board& board_, City c,int n ) : Player(board_, c, "Scientist"),number(n){}

             Player& discover_cure(Color color);
            
    };
};