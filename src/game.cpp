#include <stdexcept>
#include <vector>
#include <string>

#include "game.h"

using std::vector, std::string;

Game::Game(const int size, const int victory_sequence, const Piece &current_player)
    : board(size, victory_sequence),
      current_player(current_player)
{
}

Piece Game::get_current_player() const
{
    return current_player;
}

void Game::play(const int position)
{
    board.set_player(position, current_player);
    current_player = (current_player == Piece::X) ? Piece::O : Piece::X;
}

bool Game::game_over() const
{
    return get_state() == State::X_WIN || get_state() == State::O_WIN || get_state() == State::DRAW;
}

State Game::get_state() const
{
    if (board.get_winner() != Piece::EMPTY) {
        return (board.get_winner() == Piece::O) ? State::O_WIN : State::X_WIN;
    }
    if (board.is_full()) {
        return State::DRAW;
    }
    return (current_player == Piece::O) ? State::O_TURN : State::X_TURN;
}

Board Game::get_board() const {
    return board;
}
