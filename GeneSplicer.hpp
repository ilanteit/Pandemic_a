#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <string>

namespace pandemic{

    class GeneSplicer : public Player{


        public:
            GeneSplicer(Board& board_, City c) : Player(board_, c, "GeneSplicer"){}

            Player& discover_cure();
    };
};