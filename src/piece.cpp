#include <stdexcept>
#include <cctype>
#include <string>

#include "piece.h"

using std::string;

Piece PieceUtils::from_char(char value) {
    switch (std::toupper(value)) {
        case 'X': return Piece::X;
        case 'O': return Piece::O;
        case ' ': return Piece::EMPTY;
        default: throw std::invalid_argument("Invalid piece value: " + string(1, value));
    }
}

char PieceUtils::to_char(Piece piece) {
    switch (piece) {
        case Piece::X: return 'X';
        case Piece::O: return 'O';
        case Piece::EMPTY: return ' ';
        default: throw std::invalid_argument("Invalid piece value");
    }
}

bool PieceUtils::equals(const Piece& a, const Piece& b) {
    return a == b;
}

bool PieceUtils::equals(const Piece& piece, char value) {
    return to_char(piece) == value;
}
