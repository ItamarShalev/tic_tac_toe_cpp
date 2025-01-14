#include <stdexcept>
#include <map>
#include <string>

#include "state.h"

using std::string;

State StateUtils::from_str(const string &value)
{
    static const std::map<string, State> str_to_state{
        {"X_WIN", State::X_WIN},
        {"O_WIN", State::O_WIN},
        {"DRAW", State::DRAW},
        {"X_TURN", State::X_TURN},
        {"O_TURN", State::O_TURN}
    };

    if (str_to_state.contains(value))
    {
        return str_to_state.at(value);
    }
    throw std::invalid_argument("Invalid State value: " + value);
}

bool StateUtils::game_over(State state)
{
    return state == State::X_WIN || state == State::O_WIN || state == State::DRAW;
}

string StateUtils::state_to_str(State state)
{
    switch (state)
    {
        case State::X_WIN: return "X_WIN";
        case State::O_WIN: return "O_WIN";
        case State::DRAW: return "DRAW";
        case State::X_TURN: return "X_TURN";
        case State::O_TURN: return "O_TURN";
        default: throw std::invalid_argument("Unknown state");
    }
}
