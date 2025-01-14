#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <utility>
#include <string>

#include "board.h"
#include "exceptions.h"

static void validate_size_and_victory_sequence(const int board_size, const int victory_seq)
{
    if (victory_seq < 2) {
        throw InvalidBoard("Victory sequence must be between 2 and the size of the board.");
    }

    if (board_size < 3) {
        throw InvalidBoard("Board size must be at least 2.");
    }

    if (victory_seq > board_size) {
        throw InvalidBoard("Victory sequence must be less than or equal to the size of the board.");
    }
}

Board::Board(const int size, const int victory_sequence)
    : size(size ? size : DEFAULT_SIZE),
      victory_sequence(victory_sequence ? victory_sequence : size),
      winner(Piece::EMPTY)
{
    validate_size_and_victory_sequence(size, victory_sequence);
    board = vector(size, vector(size, Piece::EMPTY));
}

Piece Board::get_winner() const
{
    return winner;
}

bool Board::is_full() const
{
    return std::ranges::all_of(board, [](const vector<Piece>& row) {
        return std::ranges::all_of(row, [](const Piece& piece) {
            return piece != Piece::EMPTY;
        });
    });
}

void Board::set_player(const int index, const Piece &player)
{
    if (!valid_index(index)) {
        throw InvalidIndexBoard("Invalid board index.");
    }
    if (winner != Piece::EMPTY) {
        throw InvalidIndexBoard("The game is over.");
    }
    auto [row, col] = line_column(index);
    board[row][col] = player;
    winner = winner_at(index);
}

Piece Board::operator[](const int index) const
{
    if (!valid_index(index)) {
        throw InvalidIndexBoard("Invalid board index.");
    }
    auto [row, col] = line_column(index);
    return board[row][col];
}

Piece Board::winner_at(const int index) const {
    static const std::unordered_map<std::string, std::pair<int, int>> deltas = {
        {"horizontal", std::make_pair(1, 0)},
        {"vertical", std::make_pair(0, 1)},
        {"diagonal", std::make_pair(1, 1)},
        {"reverse diagonal", std::make_pair(1, -1)}
    };

    for (const auto& [row_delta, column_delta] : std::views::values(deltas)) {
        int row, col;
        std::tie(row, col) = line_column(index);
        Piece current_piece = board[row][col];

        for (int direction : {1, -1}) {
            int sequence = 1;
            for (int step = 1; step < size; ++step) {
                int new_row = row + row_delta * step * direction;
                int new_col = col + column_delta * step * direction;

                if (new_row >= 0 && new_row < size && new_col >= 0 && new_col < size &&
                    board[new_row][new_col] == current_piece) {
                    sequence++;
                    } else {
                        break;
                    }

                if (sequence >= victory_sequence) {
                    return current_piece;
                }
            }
        }
    }

    return Piece::EMPTY;
}

std::pair<int, int> Board::line_column(const int index) const
{
    return { index / size, index % size };
}

bool Board::valid_index(const int index) const
{
    return index >= 0 && index < size * size;
}
