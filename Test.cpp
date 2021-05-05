#include <iostream>
#include "doctest.h"
#include <stdexcept>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "Medic.hpp"
#include "GeneSplicer.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <string>
using namespace std; //used to include functions such as memcpy..

TEST_CASE("OprationsExpert")
{
    Board board;
    OperationsExpert player1{board, LosAngeles};
    player1.build();
    player1.take_card(City::Chicago).take_card(City::Washington).take_card(City::Miami);
    player1.fly_direct(City::Miami);
    player1.build();
    player1.take_card(MexicoCity).take_card(SanFrancisco).take_card(London).take_card(Bogota);
    CHECK_NOTHROW(player1.fly_shuttle(Bogota));
    player1.fly_direct(London);
    player1.build();
    board[City::London] = 4;
    board.remove_cures();
    CHECK_THROWS(player1.discover_cure(Color::Blue));
    CHECK_THROWS(player1.treat(City::London));
}

TEST_CASE("Dispatcher")
{
    Board board;
    Dispatcher player{board, City::MexicoCity};
    CHECK_THROWS(player.build());
    player.take_card(MexicoCity);
    CHECK_NOTHROW(player.build());
    player.take_card(London).take_card(Seoul).take_card(Montreal);

    player.fly_direct(London);
    CHECK_THROWS(player.build());
    
    board[City::London] = 3;
    player.take_card(Madrid).take_card(NewYork).take_card(Chicago);
    CHECK_THROWS(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.treat(London));
    CHECK(board[City::London] == 0);
}


TEST_CASE("Virologist")
{
    Board board;
    Scientist player1{board, City::Seoul, 1};
    board[City::Sydney] = 1;
    board[City::London] = 1;
    player1.take_card(Seoul);
    player1.take_card(Sydney);
    player1.build();
    CHECK_NOTHROW(player1.treat(Sydney));
    CHECK_NOTHROW(player1.treat(Seoul));
    CHECK_THROWS(player1.treat(London));
}
TEST_CASE("operator []")
{
    Board board;
    board[City::Manila] = 4;
    board[City::Moscow] = 3;
    board[City::London] = 2;
    board[City::Madrid] = 1;
    board[City::Madrid] = 3;
    board[City::Mumbai] = 1;

    CHECK_NE(board[City::Manila], 3);
    CHECK(board[City::London] == 2);
    CHECK(board[City::Madrid] == 1);
    CHECK(board[City::Mumbai] == 1);
    CHECK_THROWS(board[City::Madrid] = 2);
    board[City::Algiers] = 1;
    board[City::Washington] = 0;
    CHECK(board[City::Algiers] != 4);
    CHECK(board[City::Washington] == 0);
    board[City::MexicoCity] = 2;
    CHECK(board[City::MexicoCity] != 0);
    CHECK(board[City::MexicoCity] == 2);
    board[City::NewYork] = 3;
    CHECK(board[City::NewYork] == 3);
    board[City::NewYork] = 4;
    CHECK(board[City::NewYork] == 4);
    board[City::NewYork] = 0;
    CHECK(board[City::NewYork] == 0);
}
