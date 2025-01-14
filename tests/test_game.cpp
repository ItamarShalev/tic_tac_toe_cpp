#include <gtest/gtest.h>

#include "game.h"

TEST(TicTacToeTest, TestInitialization) {
    Game game(3, 3, Piece::X);
    game.play(0);
    game.play(3);
    game.play(1);
    game.play(4);
    EXPECT_FALSE(game.game_over());
    game.play(2);
    EXPECT_TRUE(game.game_over());
}
