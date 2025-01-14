#ifndef INCLUDE_PIECE_H_
#define INCLUDE_PIECE_H_

enum class Piece {
    X,
    O,
    EMPTY
};

class PieceUtils {
 public:
    static Piece from_char(char value);

    static char to_char(Piece piece);

    static bool equals(const Piece& a, const Piece& b);

    static bool equals(const Piece& piece, char value);
};

#endif // INCLUDE_PIECE_H_
