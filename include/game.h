#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <vector>
#include <string>

#include "board.h"
#include "piece.h"
#include "state.h"

using std::vector, std::string;

class Game {
 public:
    explicit Game(int size = 0, int victory_sequence = 0, const Piece &current_player = Piece::X);

    Piece get_current_player() const;

    State get_state() const;

    Board get_board() const;

    void play(int position);

    bool game_over() const;

 private:
    Board board;
    Piece current_player;
};

#endif // INCLUDE_GAME_H_
