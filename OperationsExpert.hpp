#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class OperationsExpert : public Player{

        public:
            OperationsExpert(Board& board_, City c) : Player(board_, c, "OperationsExpert"){}

            Player& build();
            
    };
};