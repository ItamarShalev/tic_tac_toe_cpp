#include <string>

#include "exceptions.h"

using std::string;

TicTacToeException::TicTacToeException(const string& message)
    : std::runtime_error(message)
{
}

InvalidBoard::InvalidBoard(const string& message)
    : TicTacToeException(message)
{
}

InvalidSymbolBoard::InvalidSymbolBoard(const string& message)
    : InvalidBoard(message)
{
}

InvalidLinesSize::InvalidLinesSize(const string& message)
    : InvalidBoard(message)
{
}

InvalidMove::InvalidMove(const string& message)
    : TicTacToeException(message)
{
}

InvalidIndexBoard::InvalidIndexBoard(const string& message)
    : InvalidMove(message)
{
}

OccupiedCell::OccupiedCell(const string& message)
    : InvalidMove(message)
{
}

GameOver::GameOver(const string& message)
    : TicTacToeException(message)
{
}

InvalidTurn::InvalidTurn(const string& message)
    : TicTacToeException(message)
{
}
