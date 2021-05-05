#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <string>

namespace pandemic{

    class FieldDoctor : public Player{


        public:
            FieldDoctor(Board& board_, City c) : Player(board_, c, "FieldDoctor"){}

            Player& treat(City city);
    };
};