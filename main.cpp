#include <iostream>

#include "piece.h"
#include "game.h"

using std::cout, std::endl;

int main()
{
    /*
     * [0, 1, 2]
     * [3, 4, 5]
     * [6, 7, 8]
     */
    Game game(3, 3, Piece::X);
    game.play(0);
    game.play(3);
    game.play(1);
    game.play(4);
    game.play(2);
    cout << "Game over: " << std::boolalpha << game.game_over() << endl;
    cout << "Winner: " << PieceUtils::to_char(game.get_board().get_winner()) << endl;
    return 0;
}
