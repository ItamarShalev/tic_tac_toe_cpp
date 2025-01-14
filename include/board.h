#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

#include <vector>
#include <string>
#include <utility>

#include "piece.h"

using std::vector, std::string;

class Board {
 public:
    static constexpr int DEFAULT_SIZE = 3;

    explicit Board(int size = 0, int victory_sequence = 0);

    Piece get_winner() const;

    bool is_full() const;

    void set_player(int index, const Piece &player);

    Piece operator[](int index) const;

 private:
    vector<vector<Piece>> board;
    int size;
    int victory_sequence;
    Piece winner;

    Piece winner_at(int index) const;

    std::pair<int, int> line_column(int index) const;

    bool valid_index(int index) const;
};

#endif // INCLUDE_BOARD_H_
