#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

#include <string>

using std::string;

enum class State
{
    X_WIN,
    O_WIN,
    DRAW,
    X_TURN,
    O_TURN
};

class StateUtils
{
 public:
    static State from_str(const string& value);

    static bool game_over(State state);

    static string state_to_str(State state);
};

#endif // INCLUDE_STATE_H_
