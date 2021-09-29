#pragma once

#include "Player.h"

#include <vector>
#include <memory>

namespace Imc::Games::PaperScissorRock
{
    struct IGameOutcomeStrategy
    {
        virtual void GetGameOutcome(const std::vector<std::unique_ptr<Player>>& players, std::ostream& outcomes) = 0;
    };
}