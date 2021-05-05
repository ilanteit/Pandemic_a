#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;
using namespace std;

namespace pandemic
{
    Board::Board() {
       
    }
    

    bool Board::is_clean()
    {
        for(auto& city : disease_lvl){
            if(city.second != 0){
                return false;
            }
        }
        return true;
    }
    void Board::build(City city){
        this->research_station.insert(city);
    }

    void Board::remove_cures()
    {
        cure_black=false;
        cure_blue=false;
        cure_yellow=false;
        cure_red =false;
    }

    int &Board::operator[](City city)
    {
        return this->disease_lvl[city];
    }

    ostream &operator<<(ostream &out, const Board &board)
    {
        out << "the board is :";
        return out;
    }
    
    
}