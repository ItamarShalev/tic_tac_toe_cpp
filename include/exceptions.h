#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

using std::string;

class TicTacToeException : public std::runtime_error {
 public:
    explicit TicTacToeException(const string& message);
};

class InvalidBoard : public TicTacToeException {
 public:
    explicit InvalidBoard(const string& message);
};

class InvalidSymbolBoard : public InvalidBoard {
 public:
    explicit InvalidSymbolBoard(const string& message);
};

class InvalidLinesSize : public InvalidBoard {
 public:
    explicit InvalidLinesSize(const string& message);
};

class InvalidMove : public TicTacToeException {
 public:
    explicit InvalidMove(const string& message);
};

class InvalidIndexBoard : public InvalidMove {
 public:
    explicit InvalidIndexBoard(const string& message);
};

class OccupiedCell : public InvalidMove {
 public:
    explicit OccupiedCell(const string& message);
};

class GameOver : public TicTacToeException {
 public:
    explicit GameOver(const string& message);
};

class InvalidTurn : public TicTacToeException {
 public:
    explicit InvalidTurn(const string& message);
};

#endif // INCLUDE_EXCEPTIONS_H_
